# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main( int argc, char *argv[]){

int rc=fork();
if (rc<0){
fprintf(stderr,"fork failed \n");
exit(1);
}
else if (rc==0){
printf("hello\n");
}
else{
printf("goodbye\n");
}
return 0;

/*
Name: Concepta Njolima
Question 1: No, I was not able to get the child process to always print first without the wait() in the parent
*/
}

