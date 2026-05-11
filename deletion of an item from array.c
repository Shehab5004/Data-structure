#include<stdio.h>
int main()
{
   int ar[100],i,n,p;
   printf("enter the num of elements");
   scanf("%d",&n);
   printf("enter elements");
   for(i=0;i<n;i++){
    scanf("%d",&ar[i]);
   }
   printf("enter deletion index");
   scanf("%d",&p);
   if(p<=0||p>n){printf("deletion not possible");}
   else{
        for(i=p-1;i<n-1;i++){
            ar[i]=ar[i+1];
            for(i=0;i<n-1;i++){
                printf("%d\n",ar[i]);
            }
        }
        }
    return 0;
}

