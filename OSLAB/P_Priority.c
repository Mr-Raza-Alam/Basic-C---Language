#include <stdio.h>

struct Process {
    int pid, pri, at, bt, ct, tat, wt, remaining_bt;
};

// Function to find process with highest priority at current time
int selectProcess(struct Process p[], int n, int curr_time) {
    int idx = -1;
    int curr_pri = -1;
    for (int i = 0; i < n; i++) {
        // Process must have arrived and not finished execution
        if (p[i].at <= curr_time && p[i].remaining_bt > 0) {
            if (p[i].pri > curr_pri) {
                curr_pri = p[i].pri;
                idx = i;
            }
        }
    }
    return idx;
}

int main() {
    int n;
    printf("Enter no. of processes required as sample : ");
    scanf("%d", &n);

    struct Process p[n];
    int original_bt[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        p[i].at = i; // Automatic arrival time increasing
        printf("Enter P%d--Priority & burst times : ", i + 1);
        scanf("%d %d", &p[i].pri, &p[i].bt);
        original_bt[i] = p[i].bt;
        p[i].remaining_bt = p[i].bt;
        p[i].ct = 0; p[i].tat = 0; p[i].wt = 0;
    }

    // Display the Raw Process Table
    printf("The Raw Process Table \n\nPid\t|AT\t|Prioty\t|BT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t|%d\t|%d\t|%d\n", p[i].pid,p[i].at,p[i].pri,p[i].bt);
    }

    int completed = 0, curr_time = 0;
    int ganttC[100], timeLine[101], g = 0;
    timeLine[0] = 0;

    // Preemptive scheduling simulation
    while (completed < n) {
        int idx = selectProcess(p, n, curr_time);
        if (idx == -1) {
            // No process has arrived, increment time
            curr_time++;
        } else {
            ganttC[g] = p[idx].pid;
            p[idx].remaining_bt--;
            curr_time++;
            timeLine[g + 1] = curr_time;
            g++;
            // If process finished, update completion time
            if (p[idx].remaining_bt == 0) {
                completed++;
                p[idx].ct = curr_time;
            }
        }
    }

    float avgTat = 0, avgWt = 0;

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - original_bt[i];
        avgTat += p[i].tat;
        avgWt += p[i].wt;
    }

    // Print Gantt Chart
    printf("\nThe Gantt Chart of %d proecess \n|", n);
    for (int i = 0; i < g; i++) printf("P%d\t|", ganttC[i]);
    printf("\n");
    for (int i = 0; i <= g; i++) printf("%d\t", timeLine[i]);
    printf("\n");

    // Print the final Process Table
    printf("\n\nPid\t|AT\t|Prioty\t|BT\t|CT\t|TAT\t|WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t|%d\t|%d\t|%d\t|%d\t|%d\t|%d\n",
               p[i].pid, p[i].at, p[i].pri, original_bt[i], p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nThe average turnaround time : %.2f\n", avgTat / n);
    printf("The average waiting time : %.2f\n", avgWt / n);
    return 0;
}

