#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    if (mkfifo("./myfifo_1", 0700) == -1){//this file can be used by everybody - 0777
        printf("unable to create fifo file \n error");
        return 1;
    }


    int i, pid[argc], status, stat;
    char arg[40];
    if (argc<2) {
        printf("Usage: file textfile1...\n");
        exit(-1);
    }
    strcpy(arg,argv[i]);
    pid[i] = fork(); 
    if (pid[i] == 0) {      // child process
        if (execl("./child.exe",arg, NULL)<0) {
            printf("ERROR while start processing file %s\n",argv[i]);
            exit(-2);
        }
        else {
            printf( "processing of file %s started (pid=%d)\n", argv[i],pid[i]);
        }
    }
    
    return 0;
}