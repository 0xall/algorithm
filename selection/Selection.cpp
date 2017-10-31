// 2013011769_Kang_SeungWon_508

#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b)  { int tmp = a; a = b; b = tmp; }

void SelectionSort(int* arr, int size, int n);
void PrintArray(int* arr, int size);

int main(int argc, char* argv[]) {
    int size, *arr, i, n;

    scanf("%d%d", &size, &n);

    arr = (int*) malloc(sizeof(int) * size);

    for(i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    SelectionSort(arr, size, n);
    PrintArray(arr, size);

    free(arr);
    return 0;
}

void SelectionSort(int* arr, int size, int n) {
    int i, j, selected;

    for(i = 0; i < n; ++i) {
        selected = i;

        for(j = i + 1; j < size; ++j) {
            if(arr[j] < arr[selected]) {
                selected = j;
            }
        }

        SWAP(arr[i], arr[selected]);
    }
}

void PrintArray(int* arr, int size) {
    int i;

    for(i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
}
