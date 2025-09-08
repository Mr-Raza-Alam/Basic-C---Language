// Preemptive version of Priority algorithm for process scheduling by me

#include<stdio.h>

struct Process{
  int pid,at,bt,pri,ct,tat,wt;

};

int main(){
  // take a no. of processes as sample
  int n;
  printf("Enter a no. to take processes as sample : ");
  scanf("%d",&n);
  struct Process p[n],tmp; 
  int ganttC[2*n],t=0,k;

  // Load the table with process information by user
  for(int i = 0; i<n; i++){
    p[i].pid = i+1;
    p[i].at = i;
    printf("Enter p%d  priority ,burst time : ",i+1);
    scanf("%d %d",&p[i].pri,&p[i].bt);
    p[i].ct = 0;
    p[i].wt = 0;
  }

  // display the process table for user

  int hp = p[0].pri; // highest priority's process
  ganttC[0] = p[0].pid;
  p[0].bt -=1;
  p[0].ct +=1;
  p[0].wt -=1;
  for(int i = 1; i<n; i++){
    if(hp < p[i].pri){
        p[i].bt -=1;
        p[i].ct +=1;
        p[i].wt -=1;
        hp = p[i].pri;
        ganttC[i] = p[i].pid;
        t =i;
    }else{
        p[i-1].bt -=1;
        p[i-1].ct +=1;
        p[i-1].wt -=1;
    }
  }

  // now sort(in descending order) the processes based on priority
  for(int i = 0; i<n-1; i++){
    for(int j = i+1; j<n; j++){
        if(p[i].pri < p[j].pri){
            // swapp 
            tmp = p[i];
            p[i] = p[j];
            p[j] = tmp;
        }
    }
  }

  // now calculate ct,tat,wt
    k = t;
    t +=p[0].bt;
    p[0].ct += t;
    p[0].tat = p[0].ct - p[0].at;
    p[0].wt += p[0].tat - p[0].bt;
  for(int i = 1; i<n; i++){
    t +=p[i].bt;
    p[i].ct = t;
    p[i].tat = p[i].ct - p[i].at;
    p[i].wt += p[i].tat - p[i].bt;
    ganttC[k] = p[i].pid;
    k++;
  }

  // display
  int avgTat = 0,avgWt = 0;
  printf(" Pid|AT| BT| Pty| CT |  Tat | Wt\n");
  for(int i = 0; i<n; i++){
   printf(" %d  | %d  | %d  | %d   | %d  | %d | %d\n",p[i].pid,p[i].at,p[i].bt,p[i].pri,p[i].ct,p[i].tat,p[i].wt);
   avgTat +=p[i].tat;
   avgWt +=p[i].wt;
  }
  printf("\nThe average turnaround time of %d processes is %d\n",n,avgTat/n);
  printf("The average waiting time of %d processes is %d\n",n,avgWt/n);

  // display ganttChart of the process
  printf("The GanttChart of %d processes is given below \n",n);
  for(int i = 0; i<k; i++){
    printf("P%d ",ganttC[i]);
  }
printf("\n");
    return 0;
}

