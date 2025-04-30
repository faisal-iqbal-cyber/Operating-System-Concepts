#include <stdio.h>
#include <string.h>

int main(){
    int num;
    int i;
    int j;
    int *ptr;
    printf("How many Elements do you want to Enter : ");
    scanf("%d",&num);
    int arr[num];

    for(i=0;i<num;i++){
        printf("Enter Elements %d ",i+1);
        scanf("%d",&arr[i]);
    }
    ptr=arr;
    int sum=0;
    for(j=0;j<num;j++){
        sum+=*ptr;
        ptr++;
    }
    printf("The sum of Array is : %d",sum);






}
