#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int X[500], Y[500];
    srand(time(NULL));
    
    for(int i=0; i<500; i++) {
        X[i] = rand() % 1001;
        Y[i] = X[i]; // Aynı diziyi kopyalıyoruz ki adil karşılaştırma olsun
    }

    clock_t t;
    
    t = clock();
    insertionSort(X, 500);
    t = clock() - t;
    printf("Insertion Sort suresi: %f saniye\n", ((double)t)/CLOCKS_PER_SEC);

    t = clock();
    selectionSort(Y, 500);
    t = clock() - t;
    printf("Selection Sort suresi: %f saniye\n", ((double)t)/CLOCKS_PER_SEC);

    return 0;
}
