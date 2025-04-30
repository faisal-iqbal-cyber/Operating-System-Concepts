#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	int i;
	int bake_num=4;
	printf("Bakery Manager : Opening The Bakkery\n");
	for(i=0;i<bake_num;i++){
	
		pid_t pid=fork();
		
		
		if(pid<0){
			perror("Child is not Created");
			
		}else if(pid==0){
			printf("Baker %d Baking (PID:%d)\n", i+1,getpid());
			sleep(3);
			printf("Baker %d Baking Complete(PID:%d)\n", i+1,getpid());
			exit(0);
		}
		
	}
		
			 for (i = 0; i < bake_num; i++) {
        			wait(NULL);
    			}
		 
		printf("Bakery Manager : All Bakers has Finished\n");
	
}
