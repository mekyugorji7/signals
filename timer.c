#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

int alarms = 0;
time_t start;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarms++;
  alarm(5);
}

void int_handler(int signum)
{
  time_t end = time(NULL);
  double total = difftime(end, start);
  printf("\nTotal execution time: %0f seconds\n", total);
  printf("Total number of alarms occured: %d\n", alarms);
  exit(0);
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  signal(SIGINT, int_handler);
  alarm(5); //Schedule a SIGALRM for 5 seconds
  while (1) {
    pause(); //busy wait for signal to be delivered
    printf("Turing was right!\n");
  }
}