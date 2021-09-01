#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main (int argc, char *argv[]){
int rc=fork();
if (rc<0){
fprintf(stderr,"fork failed\n");
exit(1);
}
else{
//char *myargs[2];
//myargs[0]=strdup("/bin/ls");
//myargs[1]=NULL;
//execl(myargs[0],myargs[0],NULL);
//char *const env[]={""};
//execle(myargs[0],myargs[0],NULL,env);
//char *arg0="ls";
//execlp(arg0,arg0, myargs[1],NULL);
char *Path="bin/ls";
char *const* myargsv=[]{Path,NULL};
execv(Path,myargsv);
return 0;
}
/*
execl- ran the executable file at /bin/ls that list out all the files in coding.3 t
execle- This is similar to execl but it requires an enviroment variables array to be passed in
execlp-This variant of exec does not use the path of the program run but just the name of the program. For example, instead of passing in /bin/ls, we pass in ls
execv- works as execl with an ability to pass in other arguments except the path of the executable as a vector.
execvp-works the same as exev but with a path environment variable like ls instead of /bin/ls
execvpe-is the execv version of execle. Allows passing in an environment variables array
To understand the arguments to pass to exec variants, I used these resources:
1. https://linuxhint.com/exec_linux_system_call_c/

We need all these variants because they take different inputs and can be used to execute processes with different forms of input
*/
}
