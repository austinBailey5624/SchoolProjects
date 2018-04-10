#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256

#define BASH_EXEC  "/bin/bash"
#define FIND_EXEC  "/bin/find"
#define XARGS_EXEC "/usr/bin/xargs"
#define GREP_EXEC  "/bin/grep"
#define SORT_EXEC  "/bin/sort"
#define HEAD_EXEC  "/usr/bin/head"

int main(int argc, char *argv[])
{
  int status;
  pid_t pid_1, pid_2, pid_3, pid_4;

  if (argc != 4) {
    printf("usage: finder DIR STR NUM_FILES\n");
    exit(0);
  }


	int pipefd[2];
	int pipefda[2];
	int pipefdb[2];
	pipe(pipefd);
	pipe(pipefda);
	pipe(pipefdb);
  pid_1 = fork();


  if (pid_1 == 0)//find
  {
    /* First Child */
//		char cmdbuf[BSIZE];//copied from powerpoint
//		bzero(cmdbuf,BSIZE);//copied from powerpoint
//		sprint(cmdbuf, "%s %s -name \'*\'.[ch]",FIND_EXEC,argv[1]);//copied from powerpoint

		//piping
		dup2(pipefd[1],STDOUT_FILENO);
    close(pipefd[0]);//read P!
    //close(pipefd[1]);//writeP1//used
    close(pipefda[0]);//read P2
    close(pipefda[1]);//write P2
    close(pipefdb[0]);//read P3
    close(pipefdb[1]);//write P3
		//the first argument to a program is its own name
		execl(FIND_EXEC,FIND_EXEC, argv[1], "-name", "*.[ch]",NULL);
    //execl(FIND_EXEC,FIND_EXEC,argv[1],"-name","*.[ch]",NULL)
 //   dup2()
//		if((execl(BASH_EXEC,BASH_EXEC,"find",cmdbuf, (char *) 0))<0)
//		{
//			fprintf(stderr, "\nError execing find. ERROR#%d\n",errno);
//			return(EXIT_FAILURE);
//		}
    exit(0);
  }

  pid_2 = fork();
  if (pid_2 == 0) //grep
  {
    /* Second Child */

		dup2(pipefd[0],STDIN_FILENO);
//    close(pipefd[0]);//read P!//used
    close(pipefd[1]);//writeP1
    close(pipefda[0]);//read P2
		dup2(pipefda[1],STDOUT_FILENO);
//    close(pipefda[1]);//write P2//used
    close(pipefdb[0]);//read P3
    close(pipefdb[1]);//write P#
		execl(XARGS_EXEC,XARGS_EXEC,"grep","-c", argv[7], NULL);
    exit(0);
  }

  pid_3 = fork();
  if (pid_3 == 0) //sort
  {
    /* Third Child */
    close(pipefd[0]);//read P!
    close(pipefd[1]);//writeP1
		dup2(pipefda[0],STDIN_FILENO);
    //close(pipefda[0]);//read P2
    close(pipefda[1]);//write P2
    close(pipefdb[0]);//read P3
		dup2(pipefdb[1],STDOUT_FILENO);
    //close(pipefdb[1]);//write P3
		execl(SORT_EXEC,SORT_EXEC,"-t",":","+1.0","-2.0","--numeric","--reverse",NULL);
    exit(0);
  }

  pid_4 = fork();
  if (pid_4 == 0)//head
   {
    /* Fourth Child */
    close(pipefd[0]);//read P!
    close(pipefd[1]);//writeP1
    close(pipefda[0]);//read P2
    close(pipefda[1]);//write P2
//    close(pipefdb[0]);//read P3
		dup2(pipefdb[0],STDIN_FILENO);
    close(pipefdb[1]);//write P3
		Sprintf(str_arr,"-lines=%s",argv[3]);
		execl(HEAD_EXEC,HEAD_EXEC,str_arr,NULL);
    exit(0);
  }

  if ((waitpid(pid_1, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_2, &status, 0)) == -1) {
    fprintf(stderr, "Process 2 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_3, &status, 0)) == -1) {
    fprintf(stderr, "Process 3 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_4, &status, 0)) == -1) {
    fprintf(stderr, "Process 4 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }

  return 0;
}
