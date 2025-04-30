#include <stdio.h>
#include <string.h>
int main(){
    char name[100];
    printf("Enter Any Name : ");
    scanf("%s",name);

    int length=strlen(name);

    for(int i=length-1;i>=0;i--){
        printf("%c\n", name[i]);
    }

}
