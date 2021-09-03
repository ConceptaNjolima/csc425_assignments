#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char*argv[]){
//int file_descriptor=open("Hello.txt", O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
int pipefds[2];
char buffer[5];
//int wstatus;
int rc=fork();

if (rc<0){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if (pipe(pipefds)==-1){
perror("failed to create pipe");
exit(-1);
}
else if (rc==0){
char greeting[1][20]={"Hi"}; // Adding a null termination to end of string
close(pipefds[0]); //close the read file descriptor

printf("Child1 writing \n");
write(pipefds[1],greeting,20);
//sleep(2);
printf("done writing");
sleep(5); // wait for the writing to complete. Without this, the parent was reading before the writing was complete 

//exit(1);
//printf("Child %d \n",file_descriptor);
}
int rc1=fork();
if (rc1==0){
//int wc=waitpid(rc, &wstatus, WUNTRACED | WCONTINUED );// wait for process 0 to complete before process 1 runs
close(pipefds[1]); // close the write file descriptor to ensure reading happens after writing
//if (wc==-1){
perror("waitpid");
exit(-1);
//}
//else{
printf("Child2 reading \n");
read(pipefds[0],buffer,20);
close(pipefds[0]); // close read file descriptor
printf("Child2 read:'%s' \n",buffer); // read from the buffered greeting
exit(1);
//}
}
return 0;

/*
Name: Concepta Njolima

Used https://linuxhint.com/pipe_system_call_c/ to understand how pipes work. 
*/

}
