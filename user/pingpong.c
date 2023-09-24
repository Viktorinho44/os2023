#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    int parent_to_child[2];
    int child_to_parent[2];

    int child;


    if(pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1){
        fprintf(2,"Pipe error");
        exit(1);
    }

    child = fork();


    if(child < 0){
        fprintf(2,"Fork error");
        exit(1);
    }


    if(child == 0){
        //child procces
        close(parent_to_child[1]);
        close(child_to_parent[0]);

        char message ;

        if(read(parent_to_child[0],&message,sizeof(message)) == sizeof(message)){
            printf("%d: received ping\n", getpid());
            write(child_to_parent[1], &message, sizeof(message));
        }

        close(parent_to_child[0]);
        close(child_to_parent[1]);
        exit(0);

    }
    else{
        close(parent_to_child[0]); 
        close(child_to_parent[1]); 

        char message = 'X';
        write(parent_to_child[1], &message, sizeof(message));
        close(parent_to_child[1]);

        if (read(child_to_parent[0], &message, sizeof(message)) == sizeof(message)) {
            printf("%d: received pong\n", getpid());
        }

        close(child_to_parent[0]);


    }

    exit(0);
}