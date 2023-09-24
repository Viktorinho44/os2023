#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int isPrimes(int prime){

    if(prime <= 1) return 0;
    if (prime <= 3) return 1;
    if (prime % 2 == 0 || prime % 3 == 0) return 0;

    for(int i = 5; i * i <= prime; i+=6){
        if (prime % i == 0 || prime % (i + 2) == 0) return 0;
    }
    return 1;
}

int
main(int argc, char *argv[])
{

    if(argc != 1){
        fprintf(2,"Error");
        exit(1);
    }


    int p[2];

    if(pipe(p) == -1){
        fprintf(2,"Error");
        exit(1);
    }


    if(fork()==0){
        //child

        close(p[0]);

        for(int i = 2; i<=35; i++){
            if(isPrimes(i)){
                write(p[1],&i,sizeof(i));
            }
        }

        close(p[1]);
        exit(0);

    }

    else{
        //parent
        close(p[1]);

        int prime;

        while(read(p[0],&prime,sizeof(prime))> 0){
            printf("prime %d\n",prime);
        }

        close(p[0]);
        wait(0);
        exit(0);

    }
}