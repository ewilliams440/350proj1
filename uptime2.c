#include "types.h"
#include "stat.h"
#include "user.h"

/* ATTENTION: to ensure correct compilation of the base code, 
   stub functions for the system call user space wrapper functions are provided. 
   REMEMBER to disable the stub functions (by commenting the following macro) to 
   allow your implementation to work properly. */

#define STUB_FUNCS
#ifdef STUB_FUNCS
int uptime2(int i) {return 0;}
#endif


/* IMPORTANT INSTRUCTION: the code below should not be changed. 
    Failure to follow this instruction will lead to zero point 
	for this part */

int 
main(int argc, char * argv[])
{
	int i = atoi(argv[1]);
    
    // "msg" now holds the shutdown message provided by the user
    //shutdown2(msg);
	
    if(i<1 || i>3)
        printf(1,"Available options for uptime output: \n[\n1=seconds,\n2=days,\n3=years\n]");
    
    uint ut = uptime2(i);

    if(i == 1){
        printf(1, "Current Uptime in ticks: %d", ut);
    } else if(i == 2){
        printf(1, "Current Uptime in seconds: %d", ut);
    } else if(i == 3){
        printf(1, "Current Uptime in minutes: %d", ut);
    }

    exit(); //return 0;
}
