#include <stdio.h>
#include <stdlib.h>

int GoingOffTheCharts(int n, int arr[]) {
	
  int maxConsecutiveDays = 0;
  int consecutiveDays = 0;
	int i ;
  for (i = 0; i < n; i++) {
    if (arr[i] > 6) {
      consecutiveDays++;
      if (consecutiveDays > maxConsecutiveDays) {
        maxConsecutiveDays = consecutiveDays;
      }
    } else {
      consecutiveDays = 0;
    }
  }

  return maxConsecutiveDays;
}
int main() {
    int numFiles = 5; 
	int fileNum;
    for ( fileNum = 1; fileNum <= numFiles; fileNum++) {
        char fileName[100]; 
        sprintf(fileName, "input%d.txt", fileNum);

        FILE *file = fopen(fileName, "r");
        if (file == NULL) {
            printf("The File %s is empty.\n", fileName);
            continue; 
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

        int result = GoingOffTheCharts(n, arr);
        printf("Highest number of consecutive extended working hours for %s: %d\n", fileName, result);

        free(arr);
    }

    return 0;
}
