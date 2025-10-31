
#include <stdio.h>

struct Process {
    int pid, at, bt, ct, tat, wt, rt; // rt = remaining time
};

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    struct Process p[n];
    int finished[n];  // process finished status
    int gc[2*n];      // Gantt chart process order
    int timeLine[2*n]; // Gantt chart timestamps
    int k = 0, time = 0, done = 0;

    // Input burst times
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].at = i;   // auto set arrival = index
        printf("Enter burst time for P%d: ", i + 1); 
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;  // initialize remaining time
        finished[i] = 0;
    }

    // Display raw table
    printf("\nProcess Table\n");
    printf("Pid | AT | BT\n");
    for (int i = 0; i < n; i++)
        printf("%3d | %2d | %2d\n", p[i].pid, p[i].at, p[i].bt);

    // RR Scheduling
    while (done < n) {
        int executed = 0;
        for (int i = 0; i < n; i++) {
            if (p[i].rt > 0 && p[i].at <= time) {
                executed = 1;
                gc[k] = p[i].pid;
                timeLine[k] = time;
                k++;

                if (p[i].rt <= tq) {
                    time += p[i].rt;
                    p[i].rt = 0;
                    p[i].ct = time;
                    finished[i] = 1;
                    done++;
                } else {
                    time += tq;
                    p[i].rt -= tq;
                }
            }
        }
        if (!executed) time++; // if CPU idle
    }
    timeLine[k] = time; // final timestamp

    // Calculate TAT & WT
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < k; i++) {
        printf("|P%d\t", gc[i]);
    }
    printf("|\n");

    for (int i = 0; i <= k; i++) {
        printf("%d\t", timeLine[i]);
    }
    printf("\n");

    // Final Table
    printf("\nFinal Process Table\n");
    printf("Pid | AT | BT | CT | TAT | WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d | %d | %d | %d | %d | %d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}
 