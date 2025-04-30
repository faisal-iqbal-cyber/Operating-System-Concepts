#include <stdio.h>
int main(){
    int num1;
    int num2;
    printf("Please Enter Number1 : ");
    scanf("%d",&num1);
    printf("Please Enter Number2 : ");
    scanf("%d",&num2);

    int remainder=num1%num2;
    printf("The Remainder is : %d\n", remainder);


}
