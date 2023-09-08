#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void insert(int arr[], int n, int data) {
	
    int i = n - 1;
    while (i >= 0 && arr[i] > data) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = data;
}

double get_median(int arr[], int n) {
    if (n % 2 == 0) {
    
        int mid1 = arr[n / 2 - 1];
        int mid2 = arr[n / 2];
        return (double)(mid1 + mid2) / 2.0;
        
    } else {
        
        return (double)arr[n / 2];
    }
}

int main() {
    FILE* fp;
    int data;
    int* arr = NULL;
    int size = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error occurs while opening file\n");
        return 1;
    }

    while (fscanf(fp, "%d", &data) != EOF) {
        size++;
        arr = (int*)realloc(arr, size * sizeof(int));
        if (arr == NULL) {
            printf("There is some error while allocating the memory error\n");
            return 1;
        }

        insert(arr, size - 1, data);

        double median = get_median(arr, size);
        printf(" The Median of %d is  : %.1f\n", data, median);
    }

    free(arr);
    fclose(fp);

    return 0;
}

