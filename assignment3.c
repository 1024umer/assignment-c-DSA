#include <stdio.h>
#include <stdlib.h>

int FixingCodeInProduction(int arr[], int n, int num) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == num) {
            return mid; 
        } else if (arr[mid] < num) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    FILE *file = fopen("input3.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int num;
    fscanf(file, "%d", &num);

    int n;
    fscanf(file, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        return 1;
    }
	int i;
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            fscanf(file, "%d", &arr[i]);
        } else {
            fscanf(file, "%d,", &arr[i]);
        }
    }

    fclose(file);

    int result = FixingCodeInProduction(arr, n, num);
    printf("Index of the item %d: %d\n", num, result);

    free(arr);
    return 0;
}

