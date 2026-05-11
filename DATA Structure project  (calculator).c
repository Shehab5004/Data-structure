#include<stdio.h>
#include<stdlib.h>
int main()
{
    char op;
    printf("Enter the operator: ");
    scanf("%c",&op);
    double a,b,x,y;
    printf("Enter the values: ");
    scanf("%lf%lf",&a,&b);
    switch(op)
    {
        case'1':
            printf("%lf + %lf = %lf",a,b,a+b);
        break;
        case'-':
            printf("%lf - %lf = %lf",a,b,a-b);
        break;
        case'*':
            printf("%lf * %lf = %lf",a,b,a*b);
        break;
        case'/':
            printf("%lf / %lf = %lf",a,b,a/b);
        break;
        case'^':
            x=pow(a,b);
            printf("%lf ^ %lf = %lf",x);
        break;


    }
    return 0;
}
