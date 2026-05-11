#include<stdio.h>
int main()
{
    int ar[100],i,j,n,p;
    printf("enter number of elements\n");
    scanf("%d",&n);
    printf("enter array elements\n");
    for(i=0;i<n;i++){
         scanf("%d",&ar[i]);

    }
    printf("enter the item to insert\n");
    scanf("%d",&j);
    printf("enter inserting position\n");
    scanf("%d",&p);
    if(p>n+1||p<=0){
        printf("invalid position!");

    }
    else{
        for(i=n;i>=p;i--){
            ar[i]=ar[i-1];
        }
        ar[p-1]=j;
        n++;
        printf("array elements after insertion\n");
        for(i=0;i<n;i++){
            printf("%d",ar[i]);
        }
    }
    return 0;
    }
