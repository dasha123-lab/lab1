#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

    int middle = (left + right) / 2;
    
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    int size = right - left + 1;
    int *tempArray = (int*)malloc(size * sizeof(int));
    
    int i = left;
    int j = middle + 1;
    int k = 0;

    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            tempArray[k] = arr[i];
            i++;
        } else {
            tempArray[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle) {
        tempArray[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        tempArray[k] = arr[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = tempArray[k];
    }
    
    free(tempArray);
}

int main() {
    srand(time(NULL));

    int sizes[] = {10, 1000, 10000, 100000};
    int count = 4;

    printf("%-10s | %-15s | %-15s | %-15s\n", "Размер", "Пузырек (сек)", "Вставки (сек)", "Слияние (сек)");
    printf("----------------------------------------------------------------\n");

    for (int k = 0; k < count; k++) {
        int size = sizes[k];

        int *originalArr = (int*)malloc(size * sizeof(int));
        int *bubbleArr = (int*)malloc(size * sizeof(int));
        int *insertionArr = (int*)malloc(size * sizeof(int));
        int *mergeArr = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            originalArr[i] = rand() % 100000;
            bubbleArr[i] = originalArr[i];
            insertionArr[i] = originalArr[i];
            mergeArr[i] = originalArr[i];
        }

        clock_t start, end;
        double time_bubble, time_insertion, time_merge;

        start = clock();
        bubbleSort(bubbleArr, size);
        end = clock();
        time_bubble = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insertionSort(insertionArr, size);
        end = clock();
        time_insertion = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        mergeSort(mergeArr, 0, size - 1);
        end = clock();
        time_merge = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-10d | %-15.5f | %-15.5f | %-15.5f\n", size, time_bubble, time_insertion, time_merge);

        free(originalArr);
        free(bubbleArr);
        free(insertionArr);
        free(mergeArr);
    }

    return 0;
}
