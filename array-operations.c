#include <stdio.h>

/*
    This is a program just to practice some algorithms with arrays
*/

// function that prints an array
void printArray(int *arr, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            printf("%d, ", arr[i]);
        }
        else {
            printf("%d", arr[i]);
        }
    }
    printf("}\n");
}

// function that finds the minimum value of an array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// function that finds the maximum value of an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// function that finds the average value of an array
int findAvg(int arr[], int size) {
    int avgSum = 0;
    int avgResult = 0;

    for (int i = 0; i < size; i++) {
        avgSum += arr[i];
    }
    avgResult = avgSum / size;

    return avgResult;
}

// function that reverses an input array and saves the result in a result array
void reverseArray(int *inputArray, int *resultArray, int size) {
    for (int i = 0; i < size; i++) {
        resultArray[i] = inputArray[size - 1 - i];
    }
}

// function that orders an input array and saves the result in a result array using bubble sort
void orderArray(int *inputArray, int *resultArray, int size) {
    // copy data from input array to result array
    for (int i = 0; i < size; i++) {
        resultArray[i] = inputArray[i];
    }
    // order the result array with bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (resultArray[j] > resultArray[j + 1]) {
                int temp = resultArray[j];
                resultArray[j] = resultArray[j + 1];
                resultArray[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int myArray[] = {5, 4, 6, 8, 5, 34, 1, 7, 5, 32, 4, 23};
    const int size = sizeof(myArray) / sizeof(int);
    int min;
    int max;
    int avg;
    int reversedArray[size];
    int minToMaxArray[size];
    int maxToMinArray[size];

    // find minimum value in the array
    min = findMin(myArray, size);

    // find maximum value in the array
    max = findMax(myArray, size);

    // find average value in the array
    avg = findAvg(myArray, size);

    // reverse original array
    reverseArray(myArray, reversedArray, size);

    // order original array from min to max
    orderArray(myArray, minToMaxArray, size);

    // reverse ordered array to get max to min
    reverseArray(minToMaxArray, maxToMinArray, size);

    // print results
    printf("Original array: ");
    printArray(myArray, size);

    printf("Minimum number in the array = %i\n", min);
    printf("Maximum number in the array = %i\n", max);
    printf("Average of the array: %i\n", avg);

    printf("Reversed array: ");
    printArray(reversedArray, size);

    printf("Array ordered from minimum to maximum: ");
    printArray(minToMaxArray, size);

    printf("Array ordered from maximum to minimum: ");
    printArray(maxToMinArray, size);

    return 0;
}
