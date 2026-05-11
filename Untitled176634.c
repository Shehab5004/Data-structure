#include <stdio.h>
int main() {
int n;
scanf("%d", &n);
int a[n], b[n - 1], f[n - 2];
for (int i =0; i<n; i++)
{
    scanf("%d", &a[i]);
}
for (int i = 0; i<n-1; i++)
{
    scanf("%d", &b[i]);
}
for (int i=0; i<n-2; i++){
    scanf("%d", &f[i]);}
int missing1, missing2;
int found;
for (int i = 0; i<n; i++){
    found = 0;
for (int j = 0; j<n - 1; j++){


if(a[i] == b[j]){
found = 1;
break;}}
if(!found){
    missing1 = a[i] ;
               break;}
}
        for (int i=0 ; i<n-1; i ++){
            found =0;
            for(int j=0;j<n-2;j++){
                if (b[i]==f[j]){
                    found =1;
                    break;
                }
            }
            if(!found){
                missing2= b[i];
                break;
            }
        }
         printf("%d \n %d",missing1,missing2);
         return 0;
}
