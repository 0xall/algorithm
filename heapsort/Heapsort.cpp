// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <stdlib.h>

#define HEAP_PARENT(x) (((x) + 1) / 2)
#define HEAP_LEFT(x) ((x) * 2 + 1)
#define HEAP_RIGHT(x) ((x) * 2 + 2)
#define COMPARE(x1, x2) ( (x1) > (x2) )
#define SWAP(x, y) { int tmp = x; x = y; y= tmp; }

void Heapify(int* arr, int size, int i);
void BuildHeap(int* arr, int size);
void HeapSort(int* arr, int size, int k);
void PrintArray(int* arr, int size, int k);

int main(int argc, char* argv[]) {
    int i, N, k, *arr;

    scanf("%d%d", &N, &k);
     
    arr = (int*) malloc(sizeof(int) * N);

    for(i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    HeapSort(arr, N, k);
    PrintArray(arr, N, k);

    free(arr);
    return 0;
}

void Heapify(int* arr, int size, int i) {
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

void BuildHeap(int* arr, int size) {
    int i;

    for(i = size / 2; i >= 0; --i) {
        Heapify(arr, size, i);
    }
}

void HeapSort(int* arr, int size, int k) {
    int i;
    BuildHeap(arr, size);
    for(i = size - 1; i >= size - k; --i) {
        SWAP(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }

}

void PrintArray(int* arr, int size, int k) {
    int i;

    for(i = size - 1; i >= size - k; --i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for(i = 0; i < size - k; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

