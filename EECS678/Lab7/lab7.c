#include <stdio.h>
#include <stdlib.h>
typedef struct threeple
{
      int pid;
      int arrivalTime;
      int priority;
}threeple;
typedef int (*comparer) (const void *a, const void *b);
int printProcesses(struct threeple processes[7]);
int arrivalAscending(const void *a, const void *b)
{
      struct threeple *c = (struct threeple*)a;
      struct threeple *d = (struct threeple*)b;
      return(c->arrivalTime-d->arrivalTime);
}
int priorityDescending(const void *a, const void *b)
{
      struct threeple *c = (struct threeple*) a;
      struct threeple *d = (struct threeple*) b;
      return(d->priority-c->priority);
}
int main()
{
      int catcher;//just a dummy int because C doesnt like void functions
//      puts("Hello World");
      struct threeple processes[7]={
            {5,10,3},
            {2,4,0},
            {7,14,0},
            {3,6,1},
            {1,2,1},
            {4,8,2},
            {6,12,3}
      };
//      processes[0]={5,10,3};
//      processes[1]={2,4,0};
//      processes[2]={7,14,0};
//      processes[3]={3,6,1};
//      processes[4]={1,2,1};
//      processes[5]={4,8,2};
//      processes[6]={6,12,3};
      puts("Sorted by Arrival (Ascending)");
      puts("Pid    ArrivalTime    Priority");
      comparer cmp= arrivalAscending;
//      void qsort(processes,7,sizeof(struct threeple), arrivalAscending);
//      qsort(processes,(int)7,sizeof(struct threeple),int (*comparer) (const void *, const void *));
      qsort(&processes,7,sizeof(struct threeple),cmp);
      catcher =printProcesses(processes);
      puts("\n\n\nSorted by Priority (Descending)");
      puts("Pid   ArrivalTime   Priority");
      cmp = priorityDescending;
//      void qsort(processes,7,sizeof(struct threeple),priorityDescending);
//      qsort(&processes,7,sizeof(struct threeple),int (*comparer) (const void *, const void *));
      qsort(&processes,7,sizeof(struct threeple),cmp);
      catcher = printProcesses(processes);
}
int printProcesses(struct threeple processes[7])
{
      for(int i=0; i<7; i++)
      {
            printf("%d      %d              %d \n",processes[i].pid,processes[i].arrivalTime,processes[i].priority);
//            printf(processes[i].arrivalTime);
//            printf(processes[i].priority);
      }
      return 0;
}
