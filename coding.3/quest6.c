#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
int rc=fork();
int wstatus;

if (rc<0){
fprintf(stderr,"fork failed\n");
exit(1);
}
else if (rc==0){
//int wc=wait(NULL);
printf("Child \n");
}
else{
int wc=waitpid(rc,&wstatus, WUNTRACED| WCONTINUED);
printf("Parent %d", wc);

}
return 0;
/*

Name: Concepta Njolima
Question1: waitpid is useful in situations where we want the parent process to wait on a specific process and not all the child process.
waitpid is also useful when trying to wait on processes whose process ids are greater or less than a certain process id. 
*/
}
