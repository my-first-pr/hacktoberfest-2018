
#include<stdio.h>

/**
 * Structure for representing the Process
 */
typedef struct
{
	int PID;              /*The process ID.       */
	int arrivalTime;      /*The arrival Time.     */
	int burstTime;        /*The burst Time.       */
	int completionTime;   /*The completion Time.  */
	int turnaroundTime;   /*The turn around Time. */
	int waitingTime;      /*The waiting Time.     */
	int priority;         /*The priority.         */
	int processed;        /*The flag denoting the process has been processed. */
	int timeAllocated;    /*The amount of CPU time given in RR.*/
}PROCESS;

int noofProcess = 0;      /*The no. of process counter.   */
PROCESS process[20];      /*The process array.            */
PROCESS sjfp[20];
float avgTATime = 0;      /*The average turn around time. */
float avgWTime  = 0;      /*The average waiting time.     */
int schdProcess[20];


void print();
void display();
void sortArrivalTime();
void clearFields();
void sjf();

int main()
{
	int i;
	
	printf("\nEnter the total no. of Processes: ");
	scanf("%d",&noofProcess);
	
	if(noofProcess > 20)
	{
		printf("\nThe maximum no. of process is limited to 20.");
	}
	else
	{
		for(i=0;i<noofProcess;i++)
		{
			printf("Enter the arrival time, burst time and priority of the process P%d: ",i);
			scanf("%d%d%d",&process[i].arrivalTime,&process[i].burstTime,&process[i].priority);
			process[i].PID = i;
	    }
		
			print();
			sortArrivalTime();
			display();
			print();
			clearFields();
			sjf();
			display();
			print();
		
	}
	return(0);
}

void print()
{
	int i;
	printf("\n-------------------------------------------------------------------");
	printf("\n| %-8s| %-8s| %-8s| %-8s| %-8s| %-8s| %-8s|","PID","AT","BT","PR","CT","WT","TAT");
	printf("\n-------------------------------------------------------------------");
	
	for(i=0;i<noofProcess;i++)
	{
		printf("\n| P%-7d| %-8d| %-8d| %-8d| %-8d| %-8d| %-8d|",process[i].PID,
		                                   process[i].arrivalTime,
										   process[i].burstTime,
										   process[i].priority,process[i].completionTime,process[i].waitingTime,process[i].turnaroundTime);
		printf("\n-----------------------------------------------------------------------");
	}
	printf("\nAVERAGE WAITING TIME: %f AVERAGE TURNAROUND TIME: %f\n\n",avgWTime,avgTATime);
	
}


void clearFields()
{
	int i;
	
	for(i=0;i<noofProcess;i++)
	{
		process[i].completionTime = 0;
		process[i].turnaroundTime = 0;
		process[i].waitingTime = 0;
		process[i].processed = 0;
		process[i].timeAllocated = 0;
		
		schdProcess[i]=0;
	}
	
	avgTATime = 0;
	avgWTime = 0;
}


void sortArrivalTime()
{
	int i,j,limit;
	PROCESS temp;
	
	for(i=0;i<noofProcess-1;i++)
	{
		limit = (noofProcess-i-1);
		for(j=0;j<limit;j++)
		{
			if(process[j].arrivalTime > process[j+1].arrivalTime)
			{
				temp = process[j];
				process[j] = process[j+1];
				process[j+1] = temp;
			}
		}
	}
}



void display()
{
	int i,temp;
	
	/*Calculation of the completion time for the first process in the queue. */
	process[0].completionTime = 0+process[0].arrivalTime + process[0].burstTime;
	process[0].turnaroundTime = process[0].completionTime - process[0].arrivalTime;
	process[0].waitingTime = process[0].turnaroundTime - process[0].burstTime;
	avgTATime = process[0].turnaroundTime;
	avgWTime = process[0].waitingTime;
	schdProcess[0] = 0;
	
	for(i=1;i<noofProcess;i++)
	{
		temp = 0;
		
		if(process[i].arrivalTime > process[i-1].completionTime)
		{
			temp = process[i].arrivalTime - process[i-1].completionTime;
		}
		
		process[i].completionTime = temp + process[i-1].completionTime + process[i].burstTime;
		process[i].turnaroundTime = process[i].completionTime - process[i].arrivalTime;
		process[i].waitingTime = process[i].turnaroundTime - process[i].burstTime;
		
		avgTATime += process[i].turnaroundTime;
		avgWTime += process[i].waitingTime;
		
		schdProcess[i] = i;
	}
	
	avgTATime /= noofProcess;
	avgWTime /= noofProcess;
}

void sjf()
{
    int c=process[0].arrivalTime;
    int i=0,j,min,count=0;
    int sch[20];
    while(i<noofProcess)
    {
        if(!process[i].processed)
	{
	    min=i;
	    for(j=0;j<noofProcess;j++)
	    {
		if((!process[j].processed) && (process[j].arrivalTime<=c) && (process[j].burstTime<process[min].burstTime))
		{
	            min=j;
		}
	    }
	    process[min].processed=1;
	    sch[count]=min;
	    count++;
	    c=c+process[min].burstTime;
	    if(i==min)
	    {
	        i++;
	    }
  	}
	else 
	{
	    i++;
	}    
    }
    for(i=0;i<noofProcess;i++)
    {
	process[i]=process[sch[i]];
    }
}

