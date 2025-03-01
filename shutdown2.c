#include "types.h"
#include "stat.h"
#include "user.h"
#include "x86.h"

/* ATTENTION: to ensure correct compilation of the base code, 
   stub functions for the system call user space wrapper functions are provided. 
   REMEMBER to disable the stub functions (by commenting the following macro) to 
   allow your implementation to work properly

#define STUB_FUNCS
#ifdef STUB_FUNCS
void shutdown2(char * msg) {}
#endif*/

void shutdown2(char * msg){
	printf(1,"%s\n",msg);
	outw(0xB004, 0x0|0x2000);
	outw(0x604, 0x0|0x2000);
}


int 
main(int argc, char * argv[])
{
	char msg[128] = {0};
	char * p = msg;
	int i = 0;
	 
    for (i = 1; i < argc; i++) 
	{
	    strcpy(p, argv[i]);
		p += strlen(argv[i]) + 1;
		if (p >= msg + sizeof(msg))
		{
			p = msg + sizeof(msg);
			break;
		}
		else
		{
			*(p - 1) = ' ';
		}
	}
	
	*(p - 1) = 0;
	
	// "msg" now holds the shutdown message provided by the user
    shutdown2(msg);
	
    exit(); //return 0;
}
