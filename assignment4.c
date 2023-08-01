#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int SelectingTheMedian(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);

    int medianIndex = n / 2;

    return arr[medianIndex];
}

int main() {
    FILE *file = fopen("input4.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error.\n");
        fclose(file);
        return 1;
    }
	int i;
    for ( i = 0; i < n; i++) {
        if (i == n - 1) {
            fscanf(file, "%d", &arr[i]);
        } else {
            fscanf(file, "%d,", &arr[i]);
        }
    }

    fclose(file);

    int result = SelectingTheMedian(arr, n);
    printf("Median value: %d\n", result);

    free(arr);
    return 0;
}
