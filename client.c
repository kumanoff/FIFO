#define _POSIX_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(){//int argc, char* argv[]
    int input_Fd = open("myfifo_1", O_RDONLY);
    if (input_Fd == -1){
        printf("client can't read \n");
        return 1;
    }

    char name_of_file;
    /*
    if(read(input_Fd, &name_of_file, sizeof(int))== -1){
        printf("can't read \n");
        return 2;
    }*/

    int numRead;
    while (( numRead = read(input_Fd, &name_of_file, 1) > 0)){
        printf("%s", &name_of_file);
    }
    printf("\n");
    

    /*for (int i=0;i<40;i++){
        printf("name of file = %s\n", name_of_file[i]);
    }*/
    close(input_Fd);
    return 0;
}