#include <stdio.h>
int main(){

    int sum=0;
    int i=2;
    while(i<=100){
        if(i%2==0){
            sum+=i;
        }
        i++;
    }
    printf("The sum of all Even Number From (2-100) is : %d",sum);



}
