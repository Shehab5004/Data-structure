#include <stdio.h>
#define MAX_SIZE 100
int main() {
int matrix[MAX_SIZE][MAX_SIZE];
int size;
printf("Enter the size of the matrix: ");
scanf("%d", &size);
printf("Enter the elements of the matrix:\n");
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
scanf("%d", &matrix[i][j]);
}
}
int diagonalSum = 0;
int nonDiagonalSum = 0;
for (int i = 0; i < size; i++) {
for (int j = 0; j < size; j++) {
if (i == j) {
diagonalSum += matrix[i][j];
} else {
nonDiagonalSum += matrix[i][j];
}
}
}
printf("Sum of diagonal elements: %d\n", diagonalSum);
printf("Sum of non-diagonal elements: %d\n", nonDiagonalSum);
return 0;
}
