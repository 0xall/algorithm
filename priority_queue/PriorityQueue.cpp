// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define HEAP_PARENT(x) (((x) + 1) / 2 - 1)
#define HEAP_LEFT(x) ((x) * 2 + 1)
#define HEAP_RIGHT(x) ((x) * 2 + 2)
#define COMPARE(x1, x2) ( (x1) >= (x2) )
#define SWAP(x, y) { long long tmp = x; x = y; y= tmp; }

void Heapify(vector<long long>& arr, int size, int i);
void PrintArray(vector<long long>& arr);
int IncreaseOrder(vector<long long>& arr, int i);

void Insert(vector<long long>& arr, long long x);
int Extract(vector<long long>& arr);
void Change(vector<long long>& arr, int index, long long value);

int main(int argc, char* argv[]) {
    int command;
    long long arg1, arg2, ret;
    vector<long long> arr;

    while(1) {
        scanf("%d", &command);

        switch(command) {
            case 0 :  // exit the program 
                PrintArray(arr);
                exit(0);

            case 1 :  // insert
                scanf("%lld", &arg1);
                Insert(arr, arg1);
                break;

            case 2 :  // pop
                ret = Extract(arr);
                printf("%lld ", ret);
                break;

            case 3 :  // change value
                scanf("%lld%lld", &arg1, &arg2);
                Change(arr, arg1, arg2);
                break;
        }
    }

    return 0;
}

void Heapify(vector<long long>& arr, int size, int i) {
    int left, right, pointed = i;
    
    left = HEAP_LEFT(i);
    right = HEAP_RIGHT(i);

    if(left < size && COMPARE(arr[left], arr[i])) pointed = left;
    if(right < size && COMPARE(arr[right], arr[pointed])) pointed = right;
    
    if(pointed != i) {
        SWAP(arr[i], arr[pointed]);
        Heapify(arr, size, pointed);
    }
}

void PrintArray(vector<long long>& arr) {
    int i;

    printf("\n");
    
    for(i = 0; i < arr.size(); ++i) {
        printf("%lld ", arr[i]);
    }

    printf("\n");
}


int IncreaseOrder(vector<long long>& arr, int i) {
    int parent = HEAP_PARENT(i);

    while(i > 0 && COMPARE(arr[i], arr[parent])) {
        SWAP(arr[parent], arr[i]);
        i = parent;
        parent = HEAP_PARENT(i);
    }

    return i;
}


void Insert(vector<long long>& arr, long long key) {
    arr.push_back(key);
    IncreaseOrder(arr, arr.size() - 1);
}


int Extract(vector<long long>& arr) {
    int ret = arr[0];
    arr[0] = arr[arr.size() - 1];
    arr.pop_back();
    Heapify(arr, arr.size(), 0);
    return ret;
}


void Change(vector<long long>& arr, int index, long long value) {

    // because the input index starts with 1, subtract 1
    index--;

    arr[index] = value;
    Heapify(arr, arr.size(), index);
    IncreaseOrder(arr, index);
/*
    if(IncreaseOrder(arr, index) == index) {
        Heapify(arr, arr.size(), index);
    }
*/
}
