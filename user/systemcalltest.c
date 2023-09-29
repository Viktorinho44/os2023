#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    /*
    Task 1: Implement a Syscall to Print a Message

Create a new syscall in XV6 that allows a process to print a custom message to the console.
 The syscall should take a pointer to a character array as an argument and print the message to the console. 
Write a user-level program to test this new syscall.

    uint64
sys_printsys(void)
{
  char s[1000];
  if (argstr(0, s,sizeof(char*)) < 0)
    return -1;

  printf("%s", s);
  return 0;
}

TUTO IDE MAIN CODE pre usera

    char *message;

    for(int i = 0; i<sizeof(*argv);i++){
        message = argv[i];
        printsys(message);
    }


    exit(0);
    */
    


    /*

Task 2: Implement a Syscall to Get the Current Process ID

Create a syscall that returns the current process's ID (PID). 
The syscall should take no arguments and return the PID as an integer. 
Write a user-level program to test this syscall by printing the current process's PID.

uint64
sys_testpid(void){
  struct proc* p = myproc();

  return p->pid;
}
  
    */






}