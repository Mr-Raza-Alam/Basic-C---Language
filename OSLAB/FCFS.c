#include<stdio.h>

struct Process
{
  int pid,at,bt,ct,tat,wt;
};

int main(){
  int n;
  printf("Enter no. of process required as sample : ");
  scanf("%d",&n);

  struct Process p[n];
  int ganttC[n],timeLine[n+1];
  timeLine[0]=0;
  int t = 0;
  int avgTat = 0,avgWt = 0;
  // now Take process table input
  for(int i = 0;i<n; i++){
     p[i].pid = i+1;
     p[i].at = i;
     printf("Enter burst time for P%d : ",i+1);
     scanf("%d",&p[i].bt);
     p[i].ct = 0;
     p[i].tat = 0;
     p[i].wt = 0;
  }
  // Display Raw Process Table
  printf("Pid\t|AT\t|BT\n");
  for(int i=0;i<n; i++)
    printf("%d\t|%d\t|%d\n",p[i].pid,p[i].at,p[i].bt);
  printf("--------------------------------------------------------------\n");
  
// FCFS algorithm => first come first serve i.e based on arrival time of process 
  for(int i = 0; i<n; i++){
     ganttC[i]=p[i].pid;
     t +=p[i].bt;
     p[i].ct = t;
     timeLine[i+1]=t;
     p[i].tat = p[i].ct - p[i].at;
     p[i].wt = p[i].tat - p[i].bt;
     avgTat += p[i].tat;
     avgWt += p[i].wt;
  }


  //  display gantt chart
  printf("The gantt chart for %d processes\n",n);
  for(int i =0 ; i<n; i++)
     printf("|P%d\t",ganttC[i]);
  printf("|\n");
  for(int i =0 ; i<n; i++)
     printf("%d\t",timeLine[i]);  
  printf("%d\n",t);
 
  // Display Final Process Table
  printf("\n--------------------------------------------------------------");
  printf("\nPid\t|AT\t|BT\t|CT\t|TAT\t|WT\n");
  for(int i=0;i<n; i++)
    printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
  printf("--------------------------------------------------------------\n");

  printf("Avearge turnaround time = %d\n",avgTat/n);
  printf("Avearge waiting time = %d\n",avgWt/n);

  return 0;
}

