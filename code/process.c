#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

        int main(){
        
        pid_t getpid(void);
        pid_t getppid(void);
        
        printf("PID = [%d]\n",getpid());    
        printf("PPID = [%d]\n",getppid());      
        
        
             
      
        return 0;
        }
