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
    int numFiles = 4; // The number of input files you have

    // Array to store the result for each input file
    int *results = (int *)malloc(numFiles * sizeof(int));
    if (results == NULL) {
        printf("Memory allocation error for results array.\n");
        return 1;
    }
	int fileNum;
    for (fileNum = 1; fileNum <= numFiles; fileNum++) {
        char fileName[100]; // Adjust the size as needed for your file names
        sprintf(fileName, "input%d.txt", fileNum); // Construct the file name

        FILE *file = fopen(fileName, "r");
        if (file == NULL) {
            printf("The File %s is Empty.\n", fileName);
            results[fileNum - 1] = -1; // Mark -1 for the corresponding file
            continue; // Move to the next file
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

        results[fileNum - 1] = BribedQueue(n, arr);

        free(arr);
    }

    // Print the results for all input files
    int fileNums;
	for (fileNums = 1; fileNums <= numFiles; fileNums++) {
        if (results[fileNum - 1] >= 0) {
            printf("Number of bribes for input%d.txt: %d\n", fileNums, results[fileNums - 1]);
        }
    }

    free(results);
    return 0;
}
