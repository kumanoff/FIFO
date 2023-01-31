#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include <errno.h>
#include <locale.h>


int main() {
   setlocale(LC_ALL, "Rus");
   char fname[25] = "";
   char fcontent;
   char file_not_exist[] = "NO WAY\n";
   char SUCCESS[] = "SUCCESS\n";
   int fd, fd1, fd2, fd3;
   int numRead, total, openFlags;
   mode_t filePerms;
   openFlags = O_CREAT | O_WRONLY | O_TRUNC;
   filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

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
   fd2 = open(fname, O_RDONLY);//text file that we are open 
   if (fd2 == -1) {
        printf("Error opening text file file\n");
        exit(-5);
    } 
    fd3 = open("out.txt", openFlags, filePerms);//text file that we are write 
   if (fd3 == -1) {
        printf("Error opening new text file\n");
        exit(-5);
    }

   total = 0;
   while ((numRead = read(fd2, &fcontent, 1)) > 0) {
      if (fd < 0){
         write(fd1, file_not_exist, strlen(file_not_exist));//send message "file do not exist"
         exit(-6);
      }
      else{
         
         write(fd3, &fcontent, 1);
         printf("fcontent = %s \n", &fcontent);
         if (fcontent == '.') {
            fcontent = 0x0a;
            write(fd3, &fcontent, numRead);
            total++;
         }
      }
   }
   write(fd1, SUCCESS, strlen(SUCCESS));//send to client 
   printf("Amount of operations: %d\n", total);
   close (fd);
   close (fd1); 
   close (fd2); 
}