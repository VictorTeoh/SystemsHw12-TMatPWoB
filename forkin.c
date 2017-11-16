#include "forkin.h"

int childact(){
  
  printf("Child PID: %d\n", getpid());

  int range = 5+rand()%16;
  sleep(2); //change to range once done

  printf("For years I laid dormant\n");
  return range;
  //return status;
}

int main(){
  srand(time(NULL));
  int cpid, status, sTime;
  printf("Initial Message\n");
  cpid = fork();
  if(cpid){
    
    cpid = fork();
    //for the newly forked child
    if(!cpid)
      sTime = childact();
    
    else{
      status = wait(&status);
      printf("child's pid : %d\n", status);  
    }
    
  }
  
  else{ childact(); }

  return 0;
}
