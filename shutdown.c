#include "types.h"
#include "stat.h"
#include "user.h"
#include "x86.h"

/* ATTENTION: to ensure correct compilation of the base code, 
   stub functions for the system call user space wrapper functions are provided. 
   REMEMBER to disable the stub functions (by commenting the following macro) to 
   allow your implementation to work properly.
#define STUB_FUNCS
#ifdef STUB_FUNCS
void shutdown(void) {}
#endif
*/

void shutdown(void){
	outw(0xB004, 0x0|0x2000);
	outw(0x604, 0x0|0x2000);
}


/* IMPORTANT INSTRUCTION: the code below should not be changed. 
    Failure to follow this instruction will lead to zero point 
	for this part */

int 
main(int argc, char * argv[])
{
    printf(1, "BYE~\n");
    shutdown();
    exit(); //return 0;
}
