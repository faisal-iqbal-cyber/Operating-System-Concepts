#include <stdio.h>
#include <string.h>

struct student{
    char name[50];
    int rollno;
    int age;
    char adress[50];


};
int main(){
  struct student students[5];
  int i;

  for(i=0;i<5;i++){
    printf("Enter The Detail of Student %d\n ",i+1);

    printf("Enter The name : ");
    fgets(students[i].name, sizeof(students[i].name),stdin);
    students[i].name[strcspn(students[i].name,"\n")]='\0';

    printf("Enter Roll No : ");
    scanf("%d",&students[i].rollno);

    printf("Enter Age : ");
    scanf("%d",&students[i].age);
    getchar();

    printf("Enter The Adress : ");
    fgets(students[i].adress, sizeof(students[i].adress),stdin);
    students[i].adress[strcspn(students[i].adress , "\n")]='\0';

  }
  
  int j;
  for(j=0;j<5;j++){
    displayStudents(students[j]);
  }
}
    void displayStudents(struct student s ){
        printf("STUDENTS DETAILS\n");
        printf("The Name of Student is : %s\n ",s.name);
        printf("The RollNo of Student is : %d\n ",s.rollno);
        printf("The Age of Student is : %d\n ",s.age);
        printf("The Adress of Student is : %s\n ",s.adress);

    }

