#include <stdio.h>     /* standard I/O functions                         */
#include <stdlib.h>    /* exit                                           */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <string.h>
#include <signal.h>    /* signal name macros, and the signal() prototype */

/* first, define the Ctrl-C counter, initialize it with zero. */
int ctrl_c_count = 0;
int got_response = 0;
#define CTRL_C_THRESHOLD  5

/* the Ctrl-C signal handler */
void catch_int(int sig_num)
{
  /* increase count, and check if threshold was reached */
  ctrl_c_count++;
  if (ctrl_c_count >= CTRL_C_THRESHOLD) {
    char answer[30];

    /* prompt the user to tell us if to really
     * exit or not */
    printf("\nReally exit? [Y/n]: ");
    fflush(stdout);
    alarm(10);
    got_response=0;
    fgets(answer, sizeof(answer), stdin);
    if (answer[0] == 'n' || answer[0] == 'N') {
      printf("\nContinuing\n");
      fflush(stdout);
      /*
       * Reset Ctrl-C counter
       */
      ctrl_c_count = 0;
    }
    else {
      printf("\nExiting...\n");
      fflush(stdout);
      exit(0);
    }
    got_response =1;
  }
}

void catchAlarm(int sig_num)
{
  if(got_response==0)//case where we are within the input section
  {
    printf("\nUser taking too long to respond. Exiting ...\n");
    fflush(stdout);
    exit(0);
  }
  else if(got_response==1)//case where we are outside the input section
  {
    //do nothing
    return;
  }
}
//man 7 signals//kill-l shows signals//ps shows process id's
/* the Ctrl-Z signal handler */
void catch_tstp(int sig_num)
{
  /* print the current Ctrl-C counter */
  printf("\n\nSo far, '%d' Ctrl-C presses were counted\n\n", ctrl_c_count);
  fflush(stdout);
}

int main(int argc, char* argv[])
{
  struct sigaction sa;
//struct sigaction alarm;
  sigset_t mask_set;  /* used to set a signa+l masking set. */
//  sigset_t mask_set2;
  memset(&sa,0,sizeof(struct sigaction));
//  memset(&alarm,0,sizeof(struct sigaction));
  sa.sa_handler = catch_int;


//  alarm.sa_handler = catchAlarm;
  sigfillset(&mask_set);
  sigdelset(&mask_set,SIGALRM);

  sa.sa_mask=mask_set;
  sigaction(SIGINT,&sa, NULL);
  sa.sa_handler = catch_tstp;
  sigaction(SIGTSTP,&sa,NULL);
  sa.sa_handler = catchAlarm;
  sigaction(SIGALRM,&sa,NULL);
  while(1)
  {
     pause();
  }
  /* setup mask_set */

  /* set signal handlers */
  // if(sigaction(SIGINT, &sa, NULL)==-1)//https://gist.github.com/aspyct/3462238
  // {
  //     perror("Error: cannot handle SIGINT");
  // }
  // return 0;
}

// void signalHandler(int signal)
// {
//       if(signal==SIGINT)
//       {
//             ctrl_c_count++;
//       }
// }
