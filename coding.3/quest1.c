# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){
int x =5;
int rc=fork();

if (rc<0){
fprintf(stderr,"fork failed");
exit(1);
}
else if (rc ==0){
printf("child has x as: %i \n", x);
}
else{
wait(NULL);
x=20;
printf("Parent sees x as: %i \n", x);
}
return 0;
}

/*
Name: Concepta Njolima
Question 1: The variable in the child process is 5
Questions 2: When I edited the variable in the child, only the child's value changed. 
The parent process's value remained 5. When I changed the parent's value,the child's value did not change too.
The child process seems to be an exact copy of the parent process that is indepedent of the parent though.   */
