#include<iostream>
using namespace std;

void fcfs(int pid[], int n, int burst[]);
void round_robin(int pid[], int n, int burst[]);
void sjf(int pid[], int n, int burst[]);//Non-Preemptive
void swap(int &a, int &b);
void sjf_preemptive(int pid[], int n, int burst[]);

int main() 
{ 
    int n;
    cin>>n;
    
    int process[20]; 
    int  burst_time[20]; 
    
    for(int i=0;i<n;i++)
    {
    	process[i] = i+1;
    	cout<<"Burst Time for Process "<<process[i]<<": ";
    	cin>>burst_time[i];
    }
    
    //FCFS Algorithm
    cout<<"\nFCFS\n----\n";
    fcfs(process,n,burst_time);
    
    //Round Robin Scheduling Algorithm
    cout<<"\nRound Robin Scheduling\n---------------------\n";
    round_robin(process,n,burst_time);
    
    //SJF Algorithm
    cout<<"\nSJF\n---\n";
    
    cout<<"Non-Preemptive : \n";
    sjf(process, n, burst_time);
    
    cout<<"\nPreemptive : \n";
    sjf_preemptive(process, n, burst_time);

    return 0; 
}

void swap(int &a, int &b)
{
	a += b;
	b = a - b;
	a -= b;
}

void sjf_preemptive(int pid[], int n, int burst[])
{
	int waiting_time[20], temp_burst[20];
		
	for (int  i=0; i<n; i++) //temp burst time initialization
	{
		temp_burst[i] = burst[i];
		waiting_time[i] = 0;
	}
	
	bool done = false;
	
	while(!done)
	{
		int min;
		for(int i=0; i<n; i++)
		{
			if(temp_burst[i]!=0)
			{
				min = i;
				break;
			}
		}
		for(int i=0; i<n; i++)
		{
			if(temp_burst[i]<temp_burst[min] && temp_burst[i]!=0)
				min = i;
		}
		
		temp_burst[min]--;
		if(temp_burst[min]==0)
			done = true;
		
		for(int i=0; i<n; i++)
		{
			if(temp_burst[i]!=0 && i!=min)
			{
				waiting_time[i]++;
				done = false;
			}
		}			
	}
			
	int sum_wait=0, sum_turn=0;	
	cout<<"Processes\t"<<"Burst time\t"<<"Waiting time\t"<<"Turn around time\n"; 

    for (int  i=0; i<n; i++) 
    { 
        cout<<"   "<< pid[i] <<"\t\t     "<<burst[i]<<"\t\t     "<<waiting_time[i]<<"\t\t     "<<waiting_time[i]+burst[i]<<endl; 
        sum_wait += waiting_time[i];
        sum_turn += waiting_time[i] + burst[i];
    }

    cout<<"\nAverage waiting time = "<< (float)sum_wait/(float)n
        <<"\nAverage turn around time = "<< (float)sum_turn/(float)n<<endl; 
	

}


void sjf(int pid[], int n, int burst[])
{
	int temp_pid[20], temp_burst[20];
		
	for (int  i=0; i<n; i++) //temp process id initialization
	{
		temp_pid[i] = pid[i];
		temp_burst[i] = burst[i];
	}
	
	//bubble sort
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
			if(temp_burst[j]>temp_burst[j+1])
			{
				swap(temp_burst[j],temp_burst[j+1]);
				swap(temp_pid[j],temp_pid[j+1]);
			}
		}
	}
	
	fcfs(temp_pid, n, temp_burst);

}

void round_robin(int pid[], int n, int burst[])
{
    int cpu_slice,t=0;//t will be assigned cpu_slice or temp_burst[i]
    cout<<"Input Time Slice for Round Robin Scheduling = ";
    cin>>cpu_slice;
	
	
	int waiting_time[20], temp_burst[20];
	
	for (int  i=0; i<n; i++) //Initializing waiting times
	{
		waiting_time[i] = 0;
		temp_burst[i] = burst[i];
	}
	
	bool done = false;

	while(!done)
	{

		for (int  i=0; i<n; i++)
		{
			//Time consumed by the ith process
			int temp;
			if(temp_burst[i]>=cpu_slice)
				temp = cpu_slice;
			else
			{
				temp = temp_burst[i];
				done = true;
			}
			
			//decrementing remaining burst time
			temp_burst[i] -= temp;
			
			//incremeting waiting time
			for(int j=0;j<n;j++)
			{
				if(j!=i)//Not for the current process
				{
					if(temp_burst[j]!=0)//only for the processes that are not complete
					{
						waiting_time[j] += temp;
						done = false;
					}
				}
			}
		}
	}
	
	
	//Display Results
	
	int sum_wait=0, sum_turn=0;	
	cout<<"Processes\t"<<"Burst time\t"<<"Waiting time\t"<<"Turn around time\n"; 

    for (int  i=0; i<n; i++) 
    { 
        cout<<"   "<< pid[i] <<"\t\t     "<<burst[i]<<"\t\t     "<<waiting_time[i]<<"\t\t     "<<waiting_time[i]+burst[i]<<endl; 
        sum_wait += waiting_time[i];
        sum_turn += waiting_time[i] + burst[i];
    }

    cout<<"\nAverage waiting time = "<< (float)sum_wait/(float)n
        <<"\nAverage turn around time = "<< (float)sum_turn/(float)n<<endl; 

}

void fcfs(int pid[], int n, int burst[])
{	
	int waiting_time[20];//, turn_around[20];
	
	waiting_time[0] = 0;
	for (int  i=1; i<n; i++)
	{
		waiting_time[i] = waiting_time[i-1] + burst[i-1];
	}	
		
	int sum_wait=0, sum_turn=0;	
	cout<<"Processes\t"<<"Burst time\t"<<"Waiting time\t"<<"Turn around time\n"; 

    for (int  i=0; i<n; i++) 
    { 
        cout<<"   "<< pid[i] <<"\t\t     "<<burst[i]<<"\t\t     "<<waiting_time[i]<<"\t\t     "<<waiting_time[i]+burst[i]<<endl; 
        sum_wait += waiting_time[i];
        sum_turn += waiting_time[i] + burst[i];
    }

    cout<<"\nAverage waiting time = "<< (float)sum_wait/(float)n
        <<"\nAverage turn around time = "<< (float)sum_turn/(float)n<<endl; 

}
