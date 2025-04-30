#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void cal_sum(int n){
	int i;
	int sum=0;
	for(i=1;i<=5;i++){
	sum+=i;
	}
	printf("The sum will be : %d\n",sum);
}

void cal_fact(int n){
	int i;
	int fac=1;
	
	for(i=1;i<=5;i++){
	fac*=i;
	
	}
	printf("The Factiorial will be : %d\n",fac);
}
int main(){
	pid_t pid =fork();


	int num=5;
	
	if(pid<0){
		perror("Error Child Failed\n");
	
	}else if(pid==0){
		perror("Child is Created \n");
		cal_sum(num);
	}else{
		perror("Parent Execute Concurrently\n");
		cal_fact(num);
	}
	
	

}
