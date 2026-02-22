#include "types.h"
#include "stat.h"
#include "user.h"

#define NCHILD 3

int main(void)
{
  int tickets[NCHILD] = {10, 20, 40};
  int pid;

  printf(1, "Lottery fairness test\n");

  for(int i = 0; i < NCHILD; i++){
    pid = fork();

    if(pid == 0){
      settickets(tickets[i]);

      int counter = 0;
      int start = uptime();

      while(uptime() - start < 2000){
        counter++;
      }

      printf(1, "PID %d tickets=%d count=%d\n",
             getpid(), tickets[i], counter);

      exit();
    }
  }

  for(int i = 0; i < NCHILD; i++)
    wait();

  printf(1, "Done\n");
  exit();
}