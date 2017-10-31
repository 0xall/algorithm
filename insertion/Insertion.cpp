// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int* arr, int size);
void PrintArray(int* arr, int size);

int main(int argc, char* argv[]) {
    int i, size, *arr;

    scanf("%d", &size);

    arr = (int*) malloc(sizeof(int) * size);

    for(i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    InsertionSort(arr, size);
    PrintArray(arr, size);

    free(arr);
    return 0;
}

void InsertionSort(int* arr, int size) {
    int i, j, key;

    for(i = 1; i < size; ++i) {
        key = arr[i];

        j = i - 1;

        while(j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }

}

void PrintArray(int* arr, int size) {
    int i;

    for(i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
}
