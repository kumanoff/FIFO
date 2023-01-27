#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int i, pid[argc], input_Fd;
    char arg[40];
    if (argc<2) {
        printf("Usage: file textfile1...\n");
        exit(-1);
    }
    strcpy(arg,argv[i]);


    if (mkfifo("myfifo_1", 0700) == -1){//this file can be used by everybody if 0777
        printf("unable to create fifo file \n error");
        return 1;
    }
    /*pid[i] = fork(); 
    if (pid[i] == 0) {      // child process
        
    }*/
    input_Fd = open("myfifo_1", O_WRONLY);
        if (input_Fd == -1){
            printf("can't open \n");
            return 1;
        }   
        if( write(input_Fd, argv[1], sizeof(int)) == -1){
            printf("cant' write \n");
            return 3;
        }
        close(input_Fd);
    return 0;
}