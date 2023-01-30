#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int i, input_Fd;//, pid[argc]

    input_Fd = open("myfifo_1", O_WRONLY | O_CREAT | O_TRUNC, 0700);

        
    if (input_Fd == -1){
        printf("can't open \n");//
        return 1;
    }
    if( write(input_Fd, argv[1], sizeof(int)) == -1){
        printf("cant' write \n");
        return 3;
    }

    close(input_Fd);
    return 0;
}