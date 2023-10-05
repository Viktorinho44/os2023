#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{

    int p[2];

    pipe(p);

    int child = fork();


    if(child == 0){

        close(p[0]);

        char message[6] = "Hello";

        write(p[1],&message,6);

        close(p[1]);
    }
    else{

        close(p[1]);

        char message[6];

        read(p[0],&message,6);

        printf("%s",message);

        close(p[0]);
    }

    exit(0);


}