#include <stdio.h>
int main(){
    int num1;
    int num2;

    printf("Enter Number 1 : ");
    scanf("%d",&num1);
    printf("Enter Number 2 : ");
    scanf("%d",&num2);

    int sumResult=sum(num1,num2);
    int subResult=sub(num1,num2);
    int mulResult=mul(num1,num2);
    int divResult=div(num1,num2);

    printf("The Sum Result is : %d\n",sumResult);

    printf("The Sub Result is : %d\n",subResult);

    printf("The Mul Result is : %d\n",mulResult);

    printf("The Div Result is : %d\n",divResult);


}
    int sum(int a, int b){
    return a+b;

}
    int sub(int a, int b){
    return a-b;

}
    int mul(int a, int b){
    return a*b;

}
    int div(int a, int b){
    return a/b;

}

