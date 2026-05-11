#include <stdio.h>
int main()
{
int i, low, high, mid, n, key, ar[100];
printf("Enter number of elements\n");
scanf("%d",&n);
printf("Enter array elements\n");
for(i = 0; i < n; i++)
scanf("%d",&ar[i]);
printf("Enter value to find\n");
scanf("%d", &key);
low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high) {
if(ar[mid] < key)
low = mid + 1;
else if (ar[mid] == key) {
printf("%d found at index %d\n", key, mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("%d is Not found!\n", key);
return 0;
}
