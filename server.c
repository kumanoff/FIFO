#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main() {
   char fname[25] = "";
   char fcontent[2000] = "";
   char file_not_exist = "file do not exist\n";
   int fd, fd1, fd2;
   mkfifo("fifo1", 0600);
   mkfifo("fifo2", 0600);
   fd = open("fifo1", O_RDONLY);
   fd1 = open("fifo2", O_WRONLY); 
   read(fd, fname, 25);
   fd2 = open(fname, O_RDONLY);//file that we are open up  
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