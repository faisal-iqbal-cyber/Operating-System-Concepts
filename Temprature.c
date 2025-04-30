#include <stdio.h>
int main(){
    float temp;
    printf("Enter the Temprature(Fahrenheit) : ");
    scanf("%f",&temp);
    float celsius = (temp-32)*(5.0/9);

    printf("Temprature in Celsius is : %.2f", celsius);






}
