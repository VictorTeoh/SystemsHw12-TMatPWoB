#include "forkin.h"

int childAct() {
  srand(getpid()); //seed RNG to not NULL. Otherwise same number will be generated.
  printf("Child PID: %d\n", getpid());
    
  //int sleepTime = 3;
  int sleepTime = 5 + rand() % 16;
  sleep(sleepTime);
  printf("Child %d is now woke\n", getpid());
    
  return sleepTime; 
}

int main(){
  
  int ppid, cpid1, cpid2, temp, sts1, sts2;
  printf("\nInitial Message\n");
  
  ppid = getpid();
  cpid1 = fork(); //initial fork
  
  //Executables for Parent and Children
  if (cpid1) { //if parent
    temp = cpid1;
    cpid1 = 0;
    cpid2 = fork();
    if (ppid == getpid()) {
      cpid1 = temp; 
      
      waitpid(cpid1, &sts1, 0);
      waitpid(cpid2, &sts2, 0);

      printf("Child %d finished after %d seconds\n", cpid1, WEXITSTATUS(sts1)); 
      printf("Child %d Finished after %d seconds\n", cpid2, WEXITSTATUS(sts2));
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
