#include "forkin.h"

int childAct() {
  srand(getpid()); //seed RNG to not NULL. Otherwise same number will be generated.
  printf("Child PID: %d\n", getpid());
    
  int sleepTime = 1;
  //sleepTime = 5 + rand() % 16;
  sleep(sleepTime);
  printf("Child is now woke\n");
    
  return sleepTime; 
}

int main(){
  
  int cpid, status, wokeChild;
  printf("\nInitial Message\n");
  
  cpid = fork(); //initial fork
  
  //Executables for Parent and Children
  if (cpid) { //if parent
    cpid = fork();
    if (cpid) {
      wokeChild = wait(&status);
      printf("Child %d finished after %d seconds\n", wokeChild, WEXITSTATUS(status));
      printf("Parent wants children to go back to bed\n");
    }
    else {
      return childAct();
    }
  }
  else { 
    return childAct();
  } 
  
  return 0;
}
