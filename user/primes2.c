#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int isPrimes(int prime){

    if(prime <=1)return 0;
    if(prime == 2 || prime ==3)return 1;
    if(prime % 2 == 0 || prime % 3 == 0) return 0;

    for(int i =5; i*i<=prime; i+=6){
        if(prime % i == 0 || prime % (i+2) == 0) return 0;
    }

    return 1;


}


int main(int argc, int *argv[])
{


    int p1[2];
    


    int child;


    if(pipe(p1) == -1 ){
        fprintf(2,"Pipe erro");
        exit(1);

    }


    child = fork();


    if(child == 0){

        close(p1[0]);


        for(int i = 1; i<36;i++){
            if(isPrimes(i)){
                write(p1[1],&i,sizeof(i));
            }
        }
        close(p1[1]);
        exit(0);


    }
    else{

        close(p1[1]);
        int prime;
        while(read(p[0],&prime,sizeof(prime)) > 0 ){

            printf("prime: %d \n",prime);

        }

        close(p1[0]);
        wait(0);
        exit(0);

    }

   

}