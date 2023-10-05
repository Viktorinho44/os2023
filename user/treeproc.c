#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


void tree(int numberOfChilds,int current){

    int child;

    printf("Current procces is %d and the parent of it is: %d\n",getpid(),getppid());

    if(current < numberOfChilds){
        child = fork();
        if(child == 0){
            tree(numberOfChilds,current + 1);
            exit(0);
        }
        else{
            wait(0);
        }
    }



};

int
main(int argc, char *argv[])
{

    int i = atoi(argv[1]);

    tree(i,1);
    exit(0);

}


