#include <stdio.h>
#include <stdlib.h>

int BribedQueue(int n, int arr[]) {
    int bribes = 0;
    int i ;
    for (i = n - 1; i >= 0; i--) {
        if (arr[i] - (i + 1) > 2) {
            printf("Too chaotic!\n");
            return -1;
        }
        int j;
        for (j = arr[i] - 2; j < i; j++) {
            if (j >= 0 && arr[j] > arr[i]) {
                bribes++;
            }
        }
    }
    return bribes;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("The File is Empty.\n");
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
    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            fscanf(file, "%d", &arr[i]);
        } else {
            fscanf(file, "%d,", &arr[i]);
        }
    }

    fclose(file);

    int result = BribedQueue(n, arr);
    if (result >= 0) {
        printf("Number of bribes are: %d\n", result);
    }

    free(arr);
    return 0;
}
