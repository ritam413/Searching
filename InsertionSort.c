#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dynamicMemoryAllocation(int** arr, int length) {
    *arr = (int*) malloc(length * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    } else {
        printf("Memory allocated!\n");
    }
}

void generateRandomNumver(int* arr, int length, int max, int min) {
    // Define: max, min in main() and then pass them along with array and length
    // Include the following lines in the main() function:
    //     int max;
    //     printf("Enter the Maximum Range of Numbers You want to produce:  ");
    //     scanf("%d", &max);
    //     int min;
    //     printf("Enter the Minimum Range of Numbers You want to produce: ");
    //     scanf("%d", &min);

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void insertationsort(int* arr,int length){
    for (int i = 0; i < length ; i++)
    {
        int key = arr[i];
        int j=i-1;
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j - 1;
            arr[j+1] = key;
        }
        

    }
    
}

void displayArray(int* arr, int length) {
    printf("The Values in array are: ");
    for (int i = 0; i < length; i++) {
        if (i == length - 1)
            printf("%d ", arr[i]);
        else
            printf("%d , ", arr[i]);
    }
    printf("\n");
}

int main() {
    int* arr1;
    int length;

    printf("Enter the length of the array you want to create: ");
    scanf("%d", &length);

    dynamicMemoryAllocation(&arr1, length);

    int max;
    printf("Enter the Maximum Range of Numbers You want to produce:  ");
    scanf("%d", &max);
    int min;
    printf("Enter the Minimum Range of Numbers You want to produce: ");
    scanf("%d", &min);

    printf("Before Sorting :-\n");
    generateRandomNumver(arr1, length, max, min);
    displayArray(arr1, length);
    
    printf("After Sorting :-\n");
    insertationsort(arr1, length);
    displayArray(arr1, length);


    free(arr1);
    return 0;
}