#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
int file_descriptor=open("Hello.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
int rc=fork();
if (rc<0){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if (rc==0){
close(STDOUT_FILENO);
printf("Child %d\n",file_descriptor);
}
else{
wait(NULL);
printf("Parent\n");
}
return 0;

/*
Name: Concepta Njolima
Question 1:The child did not print the output after closing the descriptor 


*/

}
