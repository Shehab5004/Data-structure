#include<stdio.h>
int main(){
    int n,k,t,a=0;
    scanf("%d", &n);
    scanf("%d", &k);
    while(n != 0){
        if(n % k == 0){
            t = n/k;
            n=t;
            a++;}
        else{
            n--;
            a++;}
    }
    printf("%d", a);
    return 0;}
