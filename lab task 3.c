#include <stdio.h>
int main()
{
   int ar[100], pos, i, n;

   printf("Enter number of elements\n");
   scanf("%d", &n);

   printf("Enter array elements\n", n);

   for (i= 0; i < n; i++){
      scanf("%d", &ar[i]);
      }

   printf("Enter deletion index\n");
   scanf("%d", &pos);

   if (pos >= n+1)
      printf("Deletion not possible.\n");
   else
   {
      for (i= pos - 1; i < n - 1; i++)
         ar[i] = ar[i+1];

      printf("Resultant array:\n");

      for (i = 0; i < n - 1; i++){
         printf("%d\n", ar[i]);}
   }

   return 0;
}

