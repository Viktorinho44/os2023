#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    int child = fork();


    if(child == 0){
        printf("We are in the child procces\n");
        printf("Child pid: %d\nParent pid: %d\n",getpid(),getparentpid());

    }
    else{
        wait(0);
        printf("We are in parent \n");
        printf("Child pid: %d\nParent pid: %d\n",getpid(),getparentpid());
    }
    exit(0);


}