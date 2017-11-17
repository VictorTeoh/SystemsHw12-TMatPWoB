#include "forkin.h"

int childAct() {
  srand(getpid()); //seed RNG to not NULL. Otherwise same number will be generated.
  printf("Child PID: %d\n", getpid());
    
  //int sleepTime = 3;
  int sleepTime = 5 + rand() % 16;
  sleep(sleepTime);
  printf("Child is now woke\n");
    
  return sleepTime; 
}

int main(){
  
  int ppid, cpid, cpid2, temp, status, wokeChild;
  printf("\nInitial Message\n");
  
  ppid = getpid();
  cpid = fork(); //initial fork
  
  //Executables for Parent and Children
  if (cpid) { //if parent
    temp = cpid;
    cpid = 0;
    cpid2 = fork();
    if (ppid == getpid()) {
      cpid = temp; 
      
      wokeChild = waitpid(cpid, &status, 0);
      printf("Child %d finished after %d seconds\n", wokeChild, WEXITSTATUS(status));
      
      wokeChild = waitpid(cpid2, &status, 0);
      printf("Child %d Finished after %d seconds\n", wokeChild, WEXITSTATUS(status));
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
