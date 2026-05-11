#include<stdio.h>
long long Multinacci(int n) {
    if (n==0) {
        return 1;
    } else if (n==1) {
        return 2;
    }
     else{
        long long prev1 = 1, prev2 = 2, current;

        for (int i=2;i<n;++i) {
            current=prev1*prev2;
            prev1=prev2;
            prev2=current;
        }
        return current;
    }
}
int main(){
    int n;
    printf("Enter the position: ");
    scanf("%d", &n);
    if (n>=0 && n<=20) {
        long long result = Multinacci(n);
        printf("The %d-th value:%lld\n",n,result);
    } else {
        printf("Invalid input.");
    }
    return 0;
}
