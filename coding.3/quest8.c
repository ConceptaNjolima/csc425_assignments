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
char buffer[1025];
//int wstatus;
int rc1=fork();
int rc=fork();
char *greeting="Hi\0"; // Adding a null termination to end of string

if (rc<0 || rc1<0){
fprintf(stderr, "fork failed\n");
exit(1);
}
else if (pipe(pipefds)==-1){
perror("failed to create pipe");
exit(-1);
}
else if (rc==0){
close(pipefds[0]); //close the read file descriptor

printf("Child1 writing \n");
write(pipefds[1],greeting,strlen(greeting));
//printf("done writing");

exit(0);
//printf("Child %d \n",file_descriptor);
}
else if (rc1==0){
wait(NULL);
close(pipefds[1]); // close the write file descriptor to ensure reading happens after writing

printf("Child2 reading \n");
int n=read(pipefds[0],buffer,sizeof(buffer));
close(pipefds[0]); // close read file descriptor
printf("Child2 read:'%s' %d \n ",buffer,n); // read from the buffered greeting

exit(1);

}
else{
close(pipefds[0]);
close(pipefds[1]); // Parent process closes all file descriptors
exit(0);
}
return 0;

/*
Name: Concepta Njolima

Used https://linuxhint.com/pipe_system_call_c/ to understand how pipes work. 
*/

}
