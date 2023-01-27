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
    //(errno != EEXIST) - if errors now about existing file 
    return 0;
}