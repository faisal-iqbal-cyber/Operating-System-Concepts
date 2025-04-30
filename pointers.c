#include <stdio.h>
#include <string.h>

int main(){
    char str1[100];
    char str2[50];

    printf("Enter The String1 : ");
    scanf("%s",str1);

    printf("Enter The String2 : ");
    scanf("%s",str2);

    concatenate(str1,str2);

    printf("The String Become : %s", str1);




}
    void concatenate(char str1[], char str2[]){

    int i=0;
    int j=0;

    while(str1[i]!='\0'){
        i++;
    }
    while(str2[j]!='\0'){
            str1[i]=str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';



    }
