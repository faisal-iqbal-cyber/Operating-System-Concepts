#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int compareDescending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Swap order for descending sort
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Using qsort to sort the array
    qsort(arr, n, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    qsort(arr, n, sizeof(int), compareDescending);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
