#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
//int file_descriptor=open("Hello.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
int rc=fork();
int rc2=fork();
if (rc<0|| rc2<0){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if (rc==0){
//close(STDOUT_FILENO);
printf("Child %d\n",rc);
}
else if (rc2==0){
printf("Child2 %d",rc2);
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
