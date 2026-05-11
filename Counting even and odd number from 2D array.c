#include <stdio.h>
int main() {
int rows, cols;
printf("Enter the number of rows: ");
scanf("%d", &rows);
printf("Enter the number of columns: ");
scanf("%d", &cols);
int matrix[rows][cols];
int evenCount = 0;
int oddCount = 0;
printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("Enter element at position [%d][%d]: ", i, j);
scanf("%d", &matrix[i][j]);
if (matrix[i][j] % 2 == 0)
evenCount++;
else
oddCount++;
}
}
printf("Count of even numbers: %d\n", evenCount);
printf("Count of odd numbers: %d\n", oddCount);
return 0;
}
