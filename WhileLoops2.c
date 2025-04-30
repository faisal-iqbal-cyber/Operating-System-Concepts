#include <stdio.h>
int main(){
    int sum=0;
    int i=1;

    while(i<=10){
        sum+=i;
        i++;
    }
    printf("The Sum of set of 10 integers(1-10) are : %d", sum);

}
