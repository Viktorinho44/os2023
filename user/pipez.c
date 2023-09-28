
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

//Moja vymyslena uloha program ma vypisat Hello World || Hello Viktor cez pipes


int main(int argc,char *argv[])
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
        

        char text;

        if(read(parent_to_child[0],&text,sizeof(text)) == sizeof(text)){
            printf("Hello World ||");
            write(child_to_parent[1],&text,sizeof(text));
        }
        close(parent_to_child[0]);
        close(child_to_parent[1]);
        exit(0);

    }

    else{
        close(parent_to_child[0]);
        close(child_to_parent[1]);

        char text = 'A';

        write(parent_to_child[1],&text,sizeof(text));
        close(parent_to_child[1]);


        if(read(child_to_parent[0],&text,sizeof(text)) == sizeof(text)){
            printf(" Hello Viktor \n");
            
        }

        close(child_to_parent[0]);
             
    }


    exit(0);

}