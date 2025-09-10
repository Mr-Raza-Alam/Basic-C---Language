// Round Robin Algorithm
#include<stdio.h>

struct Process{
    int pid,at,bt,ct,tat,wt;
};

int main(){
    int n,tq;
    printf("Enter a no. of process as sample : ");
    scanf("%d",&n);
    printf("Enter a fixed time quantum : ");
    scanf("%d",&tq);
    struct Process p[n];
    int gc[2*n],finished[n];

    // prepare the process raw table
    for(int i = 0; i<n; i++){
        p[i].pid = i+1;
        p[i].at = i;
        printf("Enter p%d burst time : ",i+1);
        scanf("%d",&p[i].bt);
        finished[i] = 0;
    }

    // display the raw table of processes
    printf(" Pid| AT| BT\n");
    for(int i = 0; i<n; i++)printf(" %d| %d| %d\n",p[i].pid,p[i].at,p[i].bt);

    // main logic behind RR
    int k = -1;
    for(int i = 0; i<n; i++){
       if(p[i].bt<=0) i++;
       else{
        while(i<n){
            if(p[i].bt>0 && p[i].bt<=tq){
                gc[i] = p[i].pid;
                k++;
                p[i].bt = 0; // a process has been executed completed.
                finished[i] = -1;
            }else if(finished[i] == 0){
                p[i].bt -=tq; // execute the process for the tq time
                gc[i] = p[i].pid;
                k++;
            }
            i++; // give chance to next process and send the current process for waiting into the ready queue
        }
        i = 0;
       }
    }

    // print GanttChart 
    printf("The ganttchart of %d process is given below\n",n);
    for(int i = 0;i<k; i++) printf("P%d ",gc[i]);

    return 0;
}