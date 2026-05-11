#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){

    int op;
    printf("\t***Calculator***\n\n");

    printf("Enter 0 for quit \n");
    printf("Enter 1 for Summation \n");
    printf("Enter 2 for Subtraction \n");
    printf("Enter 3 for Multiplication \n");
    printf("Enter 4 for Division \n");
    printf("Enter 5 for Modulus\n");
    printf("Enter 6 for Power \n");
    printf("Enter 7 for Factorial \n");
    printf("Enter 8 for Square \n");
    printf("Enter 9 for Cube \n");
    printf("Enter 10 for Squareroot\n");
    printf("Enter 11 for Cuberoot \n");
    printf("Enter 12 for Sin \n");
    printf("Enter 13 for Tan \n");
    printf("Enter 14 for Cos \n");
    printf("Enter 15 for Log \n\n");

    while(1){
    printf("\nEnter the operation you want to do: ");

    scanf("%d",&op);

    switch(op)
    {
                case 0:
                    exit(0);
                case 1:
                    Summation();
                    break;
                case 2:
                    Subtraction();
                    break;
                case 3:
                    Multiplication();
                    break;
                case 4:
                    Division();
                    break;
                case 5:
                    Modulus();
                    break;
                case 6:
                    Power();
                    break;
                case 7:
                    Factorial();
                    break;
                case 8:
                    Square();
                    break;
                case 9:
                    Cube();
                    break;
                case 10:
                    Squareroot();
                    break;
                case 11:
                    Cuberoot();
                    break;
                case 12:
                    Sinc();
                    break;
                case 13:
                    Tanc();
                    break;
                case 14:
                    Cosc();
                    break;
                case 15:
                    Log();
                    break;
        }
    }
    return 0;
}

void Summation(){
    printf("Enter the numbers: ");
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Result= %.2d\n",a+b);
}

void Subtraction(){
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d%d",&a,&b);
    printf("Result= %.2d\n",a-b);
}

void Multiplication(){
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d%d",&a,&b);
    printf("Result= %.2d\n",a*b);
}

void Division(){
    float a,b;
    printf("Enter the numbers: ");
    scanf("%d%d",&a,&b);
    printf("Result= %.2f\n",a/b);
}

void Modulus(){
    int a,b;
    printf("Enter the numbers: ");
    scanf("%d%d",&a,&b);
    printf("Result= %.2d\n",a%b);
}

void Power(){
    double x,y;
    printf("Enter the base and the power: ");
    scanf("%lf%lf",&x,&y);
    double p = pow(x,y);
    printf("Result= %.2lf",p);
}

void Factorial(){
    int n,factorial;
    printf("Enter the number: ");
    scanf("%d",&n);
    factorial=1;
    for(int i=1;i<=n;i++){
        factorial*=i;
    }
    printf("Result= %.2d",factorial);
}

void Square(){
    double a;
    printf("Enter the number: ");
    scanf("%lf",&a);
    double s = pow(a,2);
    printf("Result= %.2lf",s);
}

void Cube(){
    double a;
    printf("Enter the number: ");
    scanf("%lf",&a);
    double c = pow(a,3);
    printf("Result= %.2lf",c);
}

void Squareroot(){
    double a;
    printf("Enter the number: ");
    scanf("%lf",&a);
    double r = sqrt(a);
    printf("Result= %.2lf",r);
}
void Cuberoot(){
    double a;
    printf("Enter the number: ");
    scanf("%lf",&a);
    double cr = cbrt(a);
    printf("Result= %.2lf",cr);
}
void Sinc(){
    float degree,radian,pi=3.14159;
    printf("Enter the angle: ");
    scanf("%f",&degree);
    radian=degree*(pi/180);

    printf("sin(%.4f)= %.4f",degree,sin(radian));
}
void Tanc(){
    float degree,radian,pi=3.14159;
    printf("Enter the angle: ");
    scanf("%f",&degree);
    radian=degree*(pi/180);

    printf("tan(%.4f)= %.4f",degree,tan(radian));
}
void Cosc(){
    float degree,radian,pi=3.14159;
    printf("Enter the angle: ");
    scanf("%f",&degree);
    radian=degree*(pi/180);

    printf("cos(%.4f)= %.4f",degree,cos(radian));
}
void Log(){
    double a;
    printf("Enter the number: ");
    scanf("%lf",&a);
    double l = log10(a);
    printf("Result= %.2lf",l);
}

