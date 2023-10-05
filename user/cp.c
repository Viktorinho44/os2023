#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fcntl.h"

#define BUFFSIZE 4096


int
main(int argc, char *argv[])
{

    int fd_source = open(argv[1],O_RDONLY);

    int fd_destination = open(argv[2], O_WRONLY | O_CREATE);


    char buf[BUFFSIZE];

    read(fd_source,&buf,BUFFSIZE);
    write(fd_destination,&buf,BUFFSIZE);

    close(fd_source);
    close(fd_destination);

    exit(0);


}