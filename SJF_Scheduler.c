#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<limits.h>
#include<stdbool.h>

void wait_time(int n, int a_t[], int b_t[], int w_t[]){
	int r_bt[n];
	int i;
	for(i=0;i<n;i++){
	r_bt[i]=b_t[i];

	}

	int complete = 0;//track no. of processes complete
	int t=0;//track the current time
	int f_t=0;//the time where the process is actually completed executed
	int s_a=0; // selected process arrival
	int shortest=0;// track smallest remaining time
	int min = INT_MAX; // largest value so that it is larger than all the burst time
	bool flag= false;// track the selected process is valid or not(completed of not completed)

	while(complete!=n){
		int i;
		for(i=0;i<n;i++){

			if((a_t[i]<=t) && (r_bt[i]<min) && (r_bt[i]>0)){

			min=r_bt[i];//update the variable because it default containing largest value

			shortest=i;//track the selected process index

			s_a =a_t[i];//track the arrival time

			flag =true;// process is selected sucessfully

			}//if
		}//for

		// if two proces have same burst time
		int j;
		for(j=0;j<n;j++){

			if(r_bt[j]==min){
				if(s_a>a_t[j]){
					min=r_bt[j];
					shortest=j;
					s_a=a_t[j];
					flag=true;
				}
			}

		}//for

		// if any process is not selected
		if(flag==false){
		t++;
		continue;
		}

		//otherwise

		r_bt[shortest]--;//minus 1 from selected process burst time

		min=r_bt[shortest];
		if(min<=0){
			min =INT_MAX;
		}
		//if process executed then flag false so that it is actually executed completely
		if(r_bt[shortest]==0){
			complete++;
			f_t=t+1;
			w_t[shortest]=f_t - b_t[shortest] - a_t[shortest];
			flag=false;
		}
		//if any process wait time goes to negative we make it zero (not happen-ve generally)
		if(w_t[shortest]<0){
			w_t[shortest]=0;
		}
		t++;

	}//while


}
int main(){
	int n=5;
	int a_t[5]= {3,2,4,3,1};
	int b_t[5]={3,1,2,5,4};
	int w_t[n];

	wait_time(n,a_t,b_t,w_t);

	//display wait time

	for(int i=0;i<n;i++){
		printf("Wait time of process %d is %d  : \n", i+1 , w_t[i]);
	}


}
