#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


// #include <fcntl.h> // include for open -> O_WRONLY | O_APPEND



void createProccesTree(int depth,int max,int pid);


int
main(int argc, char *argv[])
{



/*
Fork and Print: Create a task where a parent process forks a child process. 
The child process should print a message, and the parent process should wait for the child to complete before printing its own message.


    int pid;

    pid = fork();


    if(pid == 0 ){
        // child proccess
        printf("Child proccess \n");
    }
    else if(pid > 0){
        //parent
        wait(0);
        printf("Parent procces\n");
    }
    else{
        fprintf(2,"Fork error \n");
        exit(1);
    }

    exit(0);

    */


    /*
    Inter-Process Communication: Develop a task where two processes communicate using a pipe. 
    One process writes a message to the pipe, and the other process reads and prints the message. Ensure proper closing of file descriptors to avoid deadlocks.
    

    int p[2];

    int pid;

    pipe(p);

    pid = fork();

    if(pid == 0){


        close(p[0]);

        char text[5] = "ABCD\n";

        write(p[1],&text,sizeof(text));

        close(p[1]);


    }
    else if(pid > 0){

        close(p[1]);

        char text[5];
        wait(0);
        read(p[0],&text,sizeof(text));

        printf("%s",text);

        close(p[0]);
        
    }
    else{
        exit(1);
    }

    exit(0);

    */
    /*File Descriptor Duplication: Design a program that duplicates a file descriptor using the dup system call. 
    For example, open a file, duplicate its descriptor, and use both descriptors to read and write simultaneously.

    ------------------------------SKIP-------------------------------------
    */



    /*Process Tree: Create a program that generates a hierarchical process tree using multiple fork calls. 
    Each process should print its own PID and the PID of its parent process.



    

    createProccesTree(0,3,1);
    exit(0);
*/

/*Named Pipes (FIFOs): Explore the concept of named pipes (FIFOs) by creating two processes—one to write data into a FIFO and another to read from it.
 Ensure synchronization and proper cleanup.*/

 /*Pipeline Processing: Build a task where multiple processes form a pipeline. 
 Each process in the pipeline reads data from its input, processes it in some way, and passes it to the next process through pipes.
  For example, you can implement a simple text transformation pipeline.*/

  /*
  File Redirection: Develop a program that demonstrates file redirection.
   Allow the user to specify input and output files as command-line arguments and use dup or similar calls to redirect input and output accordingly.*/
   
/*
Process Synchronization: Explore process synchronization concepts using fork. 
For instance, create a scenario where multiple child processes synchronize their execution using a shared resource (e.g., a semaphore or mutex). */

/*Signal Handling: Design tasks that involve signal handling using fork. 
One process can send a signal to another process, and the receiver should handle the signal appropriately (e.g., catching and ignoring it).
*/

int child;

int p[2];
pipe(p);

child = fork();

if(child == 0 ){
    
    sleep(5);
printf("Child: Waiting for a signal from the parent...\n");
    close(p[0]);

    char message = 'A';

    write(p[1],&message,sizeof(message));

    close(p[1]);

    kill(getpid());


}

else if(child >0){
        
        close(p[1]);
        
        // Wait for the child to finish
        wait(0);
        
        char message;

        read(p[0],&message,sizeof(message));
        if(message =='A'){
            printf("Parent send singnal\n");

        }
        printf("Parent: Child process has terminated.\n");
        close(p[0]);
        
}
else{
    fprintf(2,"error");
    exit(1);
}

exit(0);


/*
Parallel Processing: Create a program that utilizes fork to parallelize a task, such as searching for a specific string in a large file.
 Measure and compare the execution time with and without parallelization.
  */




}



// void createProccesTree(int depth,int max,int pid){

//         int child;

//         printf("child : %d  parent :%d \n",getpid(),pid);

//         pid = getpid();

//         if( depth < max){

//             child = fork();

            

//             if(child == 0){
//                 createProccesTree(depth + 1,max,pid);
//                 exit(0);
//             }
//             else{
//                 wait(0);
//             }
            
//         }

        
//     }