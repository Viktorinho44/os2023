#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{


    int i = atoi(argv[1]);

    printf("Square of %d is : %d\n",i,square(i));

    exit(0);
}