#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include <errno.h>
int main() {
   char fname[25] = "";
   char fcontent[2000] = "";
   char file_not_exist = "file do not exist\n";
   int fd, fd1, fd2;
   if ((mkfifo("fifo1", 0600) < 0) && (errno != EEXIST)){
      printf("can't create fifo1\n");
      exit(-1);
   }
   if ((mkfifo("fifo2", 0600) < 0) && (errno != EEXIST)){
      printf("can't create fifo1\n");
      exit(-2);
   }
   fd = open("fifo1", O_RDONLY);
   if (fd == -1) {
        printf("Error opening fifo1 file\n");
        exit(-3);
    }
   fd1 = open("fifo2", O_WRONLY); 
   if (fd1 == -1) {
        printf("Error opening fifo2 file\n");
        exit(-4);
    }
   if ((read(fd, fname, 25)) <0){
      printf("error while reading fifo file  \n");
      exit(-6);
   }
   fd2 = open(fname, O_RDONLY);//file that we are open up
   if (fd2 == -1) {
        printf("Error opening fifo file\n");
        exit(-5);
    }  
   //printf("On server side: \n");
   while (read(fd2, fcontent, sizeof(int)) != 0) {
      //printf("%s", fcontent);
      if (fd < 0)
         write(fd1, file_not_exist, strlen(file_not_exist));//send message "file do not exist"
      else
         write(fd1, fcontent, strlen(fcontent));
   }
   close (fd);
   close (fd1); 
   close (fd2); 
}