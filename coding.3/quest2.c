#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
int file_descriptor=open("../Hello.txt",O_CREAT|O_WRONLY|O_TRUNC| S_IRWXU);
FILE *fp=fopen("../Hello.txt","w");
int rc=fork();
if (rc<0){
fprintf(stderr, "fork failed\n");
}
else if (rc==0){
printf("Child %d \n",file_descriptor);
fprintf(fp,"Child try");
}
else{
printf("Parent %d \n",file_descriptor);
fprintf(fp,"Parent try");
close(file_descriptor);
}
return 0;

/*
Name: Concepta Njolima
Question 1: Yes, both the child an parent can access the file descriptor. 
Question 2: I got a segmentation fault when I tried having the parent and child write to the same file concurrently.
*/

}
