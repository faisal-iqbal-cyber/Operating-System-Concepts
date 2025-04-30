# include <stdio.h>
int main(){
    int a;
    int b;
    int c;

    printf("Enter Value of a : ");
    scanf("%d",&a);

    printf("Enter Value of b : ");
    scanf("%d",&b);

    printf("Enter Value of c : ");
    scanf("%d",&c);

    if(a<b && a<c){

        printf("Smallest Number is : %d", a);

    }else if(b<a && b<c){

         printf("Smallest Number is : %d", b);

    }else{

        printf("Smallest Number is : %d", c);
    }




}
