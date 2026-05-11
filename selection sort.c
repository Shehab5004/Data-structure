#include <stdio.h>
void selectionSort(int arr[], int size) {
for (int i = 0; i < size - 1; i++) {
int minIndex = i;
for (int j = i + 1; j < size; j++) {
if (arr[j] < arr[minIndex]) {
minIndex = j;
}
}
int temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
void printArray(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
int main() {
int size;
printf("Enter the size of the array: ");
scanf("%d", &size);
int arr[size];
printf("Enter the elements of the array: ");
for (int i = 0; i < size; i++) {
scanf("%d", &arr[i]);
}
printf("Original array: ");
printArray(arr, size);
selectionSort(arr, size);
printf("Sorted array: ");
printArray(arr, size);
return 0;
}
