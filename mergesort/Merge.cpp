// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void MergeSort(int* arr, int p, int r);
void Merge(int* arr, int p, int q, int r);
void PrintArray(int* arr, int size);

int main() {
    int i, size, *arr;

    scanf("%d", &size);

    arr = (int*) malloc(sizeof(int) * size);

    for(i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, size);
    PrintArray(arr, size);

    free(arr);

    return 0;
}

void MergeSort(int* arr, int p, int r) {
    int mid;

    if(r - p > 1) {
        mid = (p + r) / 2;
        
        MergeSort(arr, p, mid);
        MergeSort(arr, mid, r);
        Merge(arr, p, mid, r);
    }
}

void Merge(int* arr, int p, int mid, int r) {
    int* temp, size = r - p;
    int leftIndex = 0, midIndex = size / 2;
    int rightIndex = midIndex;
    int index = p;

    temp = (int*) malloc(sizeof(int) * size);
    memcpy(temp, arr + p, sizeof(int) * size);

    while(1) {
        
        // finishing merged
        if(leftIndex == midIndex && rightIndex == size) break;

        // if right array is finished
        else if(rightIndex == size) {
            arr[index++] = temp[leftIndex++];
        }

        // if left array is finished
        else if(leftIndex == midIndex) {
            arr[index++] = temp[rightIndex++];
        }

        // if the left indexed value is greater than the right one
        else if(temp[leftIndex] > temp[rightIndex]) {
            arr[index++] = temp[leftIndex++];
        }

        else {
            arr[index++] = temp[rightIndex++];
        }
    }

    free(temp);
}

void PrintArray(int* arr, int size) {
    int i;

    for(i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }

}
