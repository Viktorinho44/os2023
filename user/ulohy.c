#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{


    int p[2];
    pipe(p);

    if(fork() == 0){
        close(p[0]);

        char message[4] = "ABCD";

        if(write(p[1],&message,sizeof(message))){
            printf("Sent\n");
        };

        close(p[1]);
    }
    else{

        close(p[1]);


        wait(0);
        char message[4];
        if(read(p[0],&message,sizeof(message))>0){
            printf("Received message : %s",message);
        }
    }
    exit(0);



}