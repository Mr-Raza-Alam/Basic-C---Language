// Non-Preemptive Version of SJF scheduling algorithm.

#include<stdio.h>

struct Process{
 int pid,at,bt,ct,tat,wt;
};

int main(){
 int n;
 printf("Enter the no. of process wants to store into ready queue.");
 scanf("%d",&n);

 int ganttC[n];
 struct Process p[n],temp;
 
 //
for(int i = 0; i<n;i++){
  p[i].pid = i+1;
  p[i].at = i;
  printf("Enter p%d burst time : ",i);
  scanf("%d",&p[i].bt);
 }

 // at t = 0, process comes and complete itself first
 ganttC[0] = p[0].pid;

 
 // sort the process based on burst time
 for(int i = 1 ; i<n-1; i++){
    for(int j = i+1; j<n; j++){
        if(p[i].bt>=p[j].bt){
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }
    }
 }

//  for(int i = 0;i<n; i++){
//     printf("%d ",p[i].bt);
//  }

// Prepare the Gantt Chart
int t = 0;
for(int i = 0; i<n; i++){
    ganttC[i] = p[i].pid;
    t +=p[i].bt;
    p[i].ct = t;
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt = p[i].tat - p[i].bt;
}

// display
int avgWt = 0,avgTat = 0;
printf(" Pid  | AT | BT | CT  | TAT | WT \n");
for(int i = 0; i<n; i++){
    printf(" %d  | %d  |  %d  |  %d  |  %d  |  %d \n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    avgTat += p[i].tat;
    avgWt += p[i].wt;
}
printf("The average waiting time for %d process is %d\n",n,avgWt/n);
printf("The average turnaround time for %d process is %d",n,avgTat/n);
// Gantt Chart
printf("\nThe gantt chart for Non-Preemptive SJF scheduling Algorithm.\n");
for(int i = 0; i<n; i++) {
  printf("P%d ",ganttC[i]);

}



printf("\n");
 return 0;    
}