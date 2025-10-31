#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;         // Process ID
    int at;          // Arrival Time
    int bt;          // Burst Time
    int rt;          // Remaining Time
    int ct;          // Completion Time
    int tat;         // Turnaround Time
    int wt;          // Waiting Time
    bool completed;  // Completion flag
};

int main() {
    int n;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    struct Process p[10];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].at = i;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].completed = false;
    }

    int complete = 0, t = 0;
    float totalWT = 0, totalTAT = 0;

    // For Gantt Chart
    int ganttPID[20]; // store process IDs in order of execution
    int ganttTime[20]; // store corresponding time values
    int gcIndex = 0;


    while (complete != n) {
        int shortest = -1;
        int minm = 9999;

        // Find the shortest remaining time process that has arrived
        for (int i = 0; i < n; i++) {
            if (p[i].at <= t && !p[i].completed && p[i].rt < minm && p[i].rt > 0) {
                minm = p[i].rt;
                shortest = i;
            }
        }

        // If no process has arrived yet
        if (shortest == -1) {
            t++;
            continue;
        }

        // Log for Gantt chart (store process and time)
        ganttPID[gcIndex] = p[shortest].pid;
        ganttTime[gcIndex] = t;
        gcIndex++;

        // Execute for 1 unit time
        p[shortest].rt--;

        // If process completes now
        if (p[shortest].rt == 0) {
            p[shortest].completed = true;
            complete++;

            p[shortest].ct = t + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;

            if (p[shortest].wt < 0)
                p[shortest].wt = 0;

            totalWT += p[shortest].wt;
            totalTAT += p[shortest].tat;
        }

        t++;
    }

    // Print process details
    printf("\n------------------------------------------");
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\n------------------------------------------\n");

    printf("Average Waiting Time = %.2f\n", totalWT / n);
    printf("Average Turnaround Time = %.2f\n\n", totalTAT / n);

    // Print Gantt chart visually
    printf("Gantt Chart Timeline:\n");
    printf(" ");

    // Process IDs
    for (int i = 0; i < gcIndex; i++)
        printf("|P%d\t", ganttPID[i]);
    printf("|\n");
    // Time markers
    for (int i = 0; i < gcIndex; i++)
        printf("%d\t", ganttTime[i]);
    printf("%d\n",t);
    return 0;
}

