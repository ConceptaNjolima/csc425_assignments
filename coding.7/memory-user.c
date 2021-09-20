# include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char * argv[]){

// program takes in the number of megabytes it will use
if (argc !=2){
printf("Received one argument! Expected the number of megabytes as the second argument\n");
}

//print the process's id
printf("The process id is %d \n",getpid());

int mem_requested=atoi(argv[1]);
printf("saved %d \n",mem_requested);
//Allocates an array

//calculate the array size
int array_size=0;
array_size=mem_requested/sizeof(int);
printf("array_size %d\n",array_size);

int *my_array;
//using calloc which is the malloc version for array
my_array=calloc(array_size,sizeof(int));
//loop through indefinately

while (1){
for (int i=0;i<array_size;i++){
//put the value of i in array element i
*(my_array+1)=i;
//printf("%d \n",*my_array+i);
}
}
free(my_array);
return 0;
}
