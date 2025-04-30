#include<stdio.h>
int main(){
	int n;
	printf("Enter the No. of Processes : ");
	scanf("%d",&n);
	
	int arrival_time[n],burst_time[n],completion_time[n],turnarround_time[n],wait_time[n];
	printf("Enter the Arrival and Burst time Process\n");
	int i;
	for(i=0;i<n;i++){
		printf("Enter The Arrival Time of Process %d : ",i+1);
		scanf("%d",&arrival_time[i]);
		
		printf("Enter The Burst Time of Process %d : ",i+1);
		scanf("%d",&burst_time[i]);
	}
	//track cpu ideal or not
	int current_time=0;
	int sum_turnarround_time=0;
	int sum_wait_time=0;
	for(i=0;i<n;i++){
		if(current_time < arrival_time[i]){
			current_time=arrival_time[i];
		}
	//calculate Completion time
		completion_time[i]= current_time + burst_time[i];
		current_time=completion_time[i];
	
	//TurnArround Time
	
		turnarround_time[i]=completion_time[i] - arrival_time[i];
		sum_turnarround_time+=turnarround_time[i];
		
	//Wait time
	
		wait_time[i]=turnarround_time[i] - burst_time[i];
		sum_wait_time+=wait_time[i];
		
	
		
	}
	float avg_turnarround_time= (float)sum_turnarround_time/n;
	float avg_wait_time= (float)sum_wait_time/n;
	int j;
	printf("Processor | Arrival time | Brust Time | Completion time | Turn Arround Time | Wait Time\n");
	for(j=0;j<n;j++){
		printf("Process %d\t %d \t\t %d \t\t %d \t\t %d \t\t %d \n",j+1,arrival_time[j],burst_time[j],completion_time[j],turnarround_time[j],wait_time[j]);
		printf("\n");
	}
	printf("The Average of TurnArround Time is : %.2f\n",avg_turnarround_time);
	printf("The Average of Wait Time is : %.2f\n",avg_wait_time);
		
		

	return 0;
	


}
