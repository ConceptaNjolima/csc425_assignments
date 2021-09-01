#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
int rc=fork();
if (rc<0){
fprintf(stderr,"fork failed\n");
exit(1);
}
else if (rc==0){
int wc=wait(NULL);
printf("Child %d \n",wc);
}
else{
//int wc=wait(NULL);
//printf("%d", wc);

}
return 0;
/*

Name: Concepta Njolima
Question1: wait returns the process ID of the terminated child process when if it is successful. 
If it fails, wait returns -1.

Question2: Using wait in the child returns -1, which signals a failed system call. 

*/
}
