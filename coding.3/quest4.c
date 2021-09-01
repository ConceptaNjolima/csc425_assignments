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
execl(/bin/ls);
}

return 0;
}
