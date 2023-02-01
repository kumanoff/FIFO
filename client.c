#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main() {
   char s[100] = "";
   char s1[2000] = ""; 
   int fd, fd1;

   fd = open("fifo1", O_WRONLY);
   if (fd == -1) {
        printf("Error opening fifo1 file\n");
        exit(-3);
    }
   fd1 = open("fifo2", O_RDONLY); 
   if (fd1 == -1) {
        printf("Error opening fifo2 file\n");
        exit(-4);
    }

   printf("\nEnter the file name:");
   scanf("%s", s);

   write(fd, s, strlen(s));
   printf("result of operation:\n");
   while (read(fd1, s1, sizeof(int))>0){
      printf("%s", s1); 
   }
   close (fd);
   close (fd1); 
}