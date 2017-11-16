#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int childact(){
  int range = 2+rand()%16; 
  sleep(range);
  printf("For years I laid dormant\n");
  return range;
  //return status;
}

int main(){
  srand(time(NULL));
  int cpid;
  int status = 1;
  printf("hello world\n");
  cpid = fork();
  if(cpid){
    
    cpid = fork();
    //for the newly forked child
    if(!cpid){ childact(); }
    
    else{
      wait(&status);
      printf("status?? : %d\n",status);  
    }
    
  }
  
  else{ childact(); }

  return 0;
}
