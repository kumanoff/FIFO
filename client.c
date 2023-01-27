#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(){//int argc, char* argv[]
    int output_Fd = open("myfifo_1", O_RDONLY);
    if (output_Fd == -1){
        printf("client can't read \n");
        return 1;
    }
    char name_of_file;
    if(read(output_Fd, &name_of_file, sizeof(int))== -1){
        printf("can't read \n");
        return 2;
    }
    printf("name of file = %s\n", name_of_file);
    close(output_Fd);
    return 0;
}