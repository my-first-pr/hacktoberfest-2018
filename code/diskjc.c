
#include<stdio.h>
#include<stdlib.h>

struct input
{
	int trackNo;       /*The track number. */
	int processed;     /*Processed flag.   */
}input[100];

/*Structure for storing the track numbers in the order they are processed. */
struct process
{
    int trackReferenced; /*Track number. */
	int seekTime;        /*Seek time.    */
}Scheduling[100]; 

int noOfTracks;                    /*Variable for storing the no. of inputs.          */
int currentArmPosition = 100;      /*Variable for retaining the initial arm position. */
int lastTrackPosition = 199;       /*Variable for retaining the last tack position.   */

void fcfs();                       /*Function implementing the FCFS algorithm.        */
void scan();                       /*Function implementing the SCAN algorithm.        */
void cscan();                      /*Function implementing the CSCAN algorithm.       */
void print(char * str);            /*Function for formatted output.                   */ 
int checkIfProcessed(int trackNo); /*Function checking whether a given track is processed. */
void clearDS();                    /*Function to clear the global intermediate result.*/

int main()
{
    printf("Enter the no of tracks:");
    scanf("%d",&noOfTracks);
    printf("Enter the trackno of each:");
    for(int i=0;i<noOfTracks;i++)
    {
        scanf("%d",&input[i].trackNo);
    }

    fcfs();
    scan();
    cscan();

}
void clearDS()
{
	int i;
	
	for(i=0;i<noOfTracks;i++)
	{
		input[i].processed = 0;
		Scheduling[i].trackReferenced =0;
		Scheduling[i].seekTime = 0;
	}
}
int checkIfProcessed(int trackNo)
{ 
	int returnValue = -1;
	int i;
	
	for(i=0;i<noOfTracks;i++)
	{
		if(inputTracks[i].trackNo == trackNo)
		{
			returnValue = (input[i].processed == 0)?i:-1;
			break;
		}
	}
	
	return(returnValue);
}
void print(char * str)
{
	int i;
	float averageSeekTime = 0;
	
	printf("\n\n%s DISK SCHEDULING DETAILS.",str);
	printf("\n----------------------------------------");
	printf("\n|%-5s |%-18s|%-12s|","SLNo","TRACK REFERENCED","SEEK TIME");
	printf("\n----------------------------------------");
    for(i=0;i<noOfTracks;i++)
	{
	    printf("\n| %-4d | %-17d| %-11d|",(i+1),Scheduling[i].trackReferenced,Scheduling[i].seekTime);
		averageSeekTime += Scheduling[i].seekTime;
	}
	printf("\n----------------------------------------");
	printf("\nAVERAGE SEEK TIME: %.2f",(averageSeekTime/noOfTracks));
	printf("\n----------------------------------------");
}
void fcfs()
{
    clearDS();
    int armposition=currentArmPosition;
    for(int i=0;i<noOfTracks;i++)
    {
        Scheduling[i].trackReferenced=input[i].trackNo;
        Scheduling[i].seekTime=abs((armposition-input[i].trackNo));
        armposition=input[i].trackNo;
    }
    
    print("FCFS");

}
void scan()
{
    clearDS();
    int armposition=currentArmPosition;
    int currentTrack=armposition;
    int i=0;
    while(i<noOfTracks)
    {
        int temp=checkIfProcessed(currentTrack);
        if(temp>=0)
        {
            Scheduling[i].trackReferenced=currentTrack;
            Scheduling[i].seekTime=abs((currentTrack-armposition));
            armposition=currentTrack;
            input[temp].processed=1;
            i++;
        }
        if(currentTrack==0)
        {
            currentTrack=currentArmPosition++;
        }
        if(currentTrack>currentArmPosition)
        {
            currentTrack++;
        }
        else
        {
            currentTrack--;
        }
    }
    print("SCAN");
}

void cscan()
{
    currentArmPosition=100;
    clearDS();
    int armposition=currentArmPosition;
    int currentTrack=armposition;
    int i=0;
    while(i<noOfTracks)
    {
        int temp=checkIfProcessed(currentTrack);
        if(temp>=0)
        {
            Scheduling[i].trackReferenced=currentTrack;
            Scheduling[i].seekTime=abs((currentTrack-armposition));
            armposition=currentTrack;
            input[temp].processed=1;
            i++;
        }
        if(currentTrack==0)
        {
            currentTrack=lastTrackPosition;
        }
        currentTrack--;
    }
    print("CSCAN");
}