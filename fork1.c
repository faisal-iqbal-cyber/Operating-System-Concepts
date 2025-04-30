#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


void even_sum(int array[],int size){
	int i;
	int even=0;
	for(i=0;i<size;i++){
		if(array[i]%2==0){
		even+=array[i];
		}
	}
	printf("The sum of Evens will be : %d\n",even);
}

void odd_sum(int array[],int size){
	int i;
	int odd=0;
	for(i=0;i<size;i++){
		if(array[i]%2!=0){
		odd+=array[i];
		}
	}
	printf("The sum of Odds will be : %d\n",odd);
}
int main(){
	


	int arr[10];
	int i;
	printf("Enter the Elements of Array\n ");
	for(i=0;i<10;i++){
		printf("Enter the Elements %d : ",i+1);
		scanf("%d",&arr[i]);
	}
	pid_t pid =fork();
	
	
	if(pid<0){
		perror("Error Child Failed\n");
	
	}else if(pid==0){
		perror("Child is Created \n");
		even_sum(arr,10);
	}else{
		perror("Parent Execute Concurrently\n");
		odd_sum(arr,10);
	}
	
	

}
