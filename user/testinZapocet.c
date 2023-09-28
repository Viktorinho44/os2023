#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int main(int argc, int *argv[])

{

    
    int parent_to_child[2];
    int child_to_parent[2];
    int child;


    

      if(pipe(parent_to_child) == -1 || pipe(child_to_parent) == -1){
        fprintf(2,"Pipe error");
        exit(1);
    }

    child = fork();


    if(child == 0){

        close(parent_to_child[1]);
        close(child_to_parent[0]);


        char t;


        if(read(parent_to_child[0],&t,sizeof(t)) == sizeof(t)){
            printf("Child ide bomoby: %d\n",getpid());
            write(child_to_parent[1],&t,sizeof(t));
            
            
        }

        close(child_to_parent[1]);
        close(parent_to_child[0]);
        exit(0);
    }

    else{

        close(child_to_parent[1]);
        
        close(parent_to_child[0]);
    


        char t = 'A';
        write(parent_to_child[1],&t,sizeof(t));
        close(parent_to_child[1]);

        if(read(child_to_parent[0],&t,sizeof(t)) == sizeof(t)){
            printf("Parent ide bomoby: %d",getpid());
        }

        close(child_to_parent[0]);
        
        

    }
exit(0);

}
