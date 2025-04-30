#include <stdio.h>
#include <string.h>

int main(){

    int Student_rollNo[5]={12,45,33,5,6};


    int i;
    for(i=0;i<5;i++){
        printf("%d \n",Student_rollNo[i]);
    }
    int i;
    int sum=0;

    int number[10]={0,1,2,3,4,5,6,7,8,9};

    int size=sizeof(number)/sizeof(number[0]);

    for(i=0;i<size;i++){

        sum+=number[i];
    }

    printf("Sum of Array is: %d\n", sum);

    float avg=sum/size;

    printf("Avrage of Array is: %f", avg);

    int array[5]={1,2,3,4,5};
    int i;
    int highest;
    int lowest;

    for(i=0;i<5;i++){

            if(array[0]<array[i]){
                highest=array[i];
            }



    }
    for(i=0;i<5;i++){

            if(array[0]>array[i]){
                lowest=array[i];
            }



    }



     printf("Highest Number is : %d\n",highest);

     printf("lowest Number is : %d\n",lowest);

     int number[5];
     int i;
     int sumOdd=0;

     for(i=0;i<5;i++){
     printf("Enter %d element :",i+1);
     scanf("%d",&number[i]);
     }
     for(i=0;i<5;i++){
         if(number[i]%2==0){
            sumOdd+=number[i];
         }

     }
     printf("Sum of Even Number are : %d",sumOdd);
     

     int number[10];
     int i;
     int countEven=0;
     int countOdd=0;

     for(i=0;i<10;i++){
     printf("Enter %d element :",i+1);
     scanf("%d",&number[i]);
     }

     for(i=0;i<10;i++){

        if(number[i]%2==0){
            countEven++;
         }

        if(number[i]%2!=0){
            countOdd++;
         }

     }

     printf("Even Count is : %d\n ",countEven);

     printf("Odd Count is : %d ",countOdd);


}
