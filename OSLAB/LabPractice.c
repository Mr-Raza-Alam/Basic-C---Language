// q3) Priority - Non Preemptive version
#include<stdio.h>

struct Process{
  int pid,pri,at,bt,ct,tat,wt;    
};

int main(){
    int n;
    printf("Enter no. of processes required as sample : ");
    scanf("%d",&n);
    
    struct Process p[n],tmp;
    // Design Raw Process Table
    for(int i = 0; i<n; i++){
        p[i].pid = i+1;
        p[i].at = i;
        printf("Enter P%d--Priority & burst times : ",i+1);
        scanf("%d %d",&p[i].pri,&p[i].bt);
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
    }

   // Display The Raw Process Table
    printf("Pid\t|AT\t|Prioty\t|BT\n");
    for(int i = 0; i<n; i++){
        printf("%d\t|%d\t|%d\t|%d\n",p[i].pid,p[i].at,p[i].pri,p[i].bt);
    }

    int ganttC[n],timeLine[n+1];
    timeLine[0]=0;
    int t=0;
    // sort processes accept first one based on priority
    for(int i = 1; i<n-1; i++){
        for(int j =i+1; j<n; j++ ){
            if(p[i].pri > p[j].pri){// swapp 
                tmp = p[i];
                p[i] = p[j];
                p[j] = tmp;
            }
        }
    }

    // Apply SJF on the given process and add process accordingly to GanttChart
    float avgTat=0,avgWt=0;
    for(int i =0; i<n; i++){
         ganttC[i] = p[i].pid;
          t = t + p[i].bt;
          p[i].ct = t;
         timeLine[i+1] = t;
         p[i].tat = p[i].ct - p[i].at;
         p[i].wt = p[i].tat - p[i].bt;
         avgTat +=p[i].tat;
         avgWt +=p[i].wt;
    }

    // Print Gantt Chart 
    printf("\nThe Gantt Chart of %d proecess \n|",n);
    for(int i =0; i<n; i++) printf("P%d\t|",ganttC[i]);
    printf("\n");
    for(int i =0; i<=n; i++) printf("%d\t",timeLine[i]);
    
    // Print the final Process Table
    printf("\n\nPid\t|AT\t|BT\t|CT\t|TAT\t|WT\n");
    for(int i = 0; i<n; i++){
        printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nThe average turnaround time : %.2f\n",avgTat/n);
    printf("The average waiting time : %.2f\n",avgWt/n);     
    
    return 0;
}
