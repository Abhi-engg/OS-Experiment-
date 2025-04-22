# Experiment No: 5

## Aim:
Write a program to implement CPU Scheduling algorithms like **FCFS** (First-Come, First-Serve).

---

## Theory:

### 1. First-Come, First-Serve Scheduling (FCFS):
FCFS is the simplest CPU scheduling algorithm. In this method, the process that enters the **ready queue** first is assigned the CPU first. The operating system maintains a data structure (typically a queue) to manage the order of execution.

Whenever a process requests the CPU, it is added to the ready queue. The process at the **head** of the queue is selected for execution.

---

## Algorithm for FCFS Scheduling:

1. Start the process.
2. Accept the number of processes in the ready queue.
3. For each process in the ready queue:
   - Assign the process ID.
   - Accept the CPU burst time.
4. Set the waiting time of the first process to `0` and its burst time as its turnaround time.
5. For each process in the queue, calculate:
   - Waiting Time = Waiting time of previous process + Burst time of previous process.
   - Turnaround Time = Waiting time + Burst time.
6. Calculate:
   - Average Waiting Time = Total waiting time / Number of processes.
   - Average Turnaround Time = Total turnaround time / Number of processes.
7. Stop the process.

---

## FCFS Scheduling Program (C Language):

```c
#include <stdio.h>

int main() {
    int i, j, n, bt[10], compt[10], at[10], wt[10], tat[10];
    float sumwt = 0.0, sumtat = 0.0, avgwt, avgtat;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of %d process(es):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time of %d process(es):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    compt[0] = bt[0] + at[0];

    for (i = 1; i < n; i++)
        compt[i] = bt[i] + compt[i - 1];

    for (i = 0; i < n; i++) {
        tat[i] = compt[i] - at[i];
        wt[i] = tat[i] - bt[i];
        sumtat += tat[i];
        sumwt += wt[i];
    }

    avgwt = sumwt / n;
    avgtat = sumtat / n;

    printf("----------------------------------\n");
    printf("PN\tBT\tCT\tTAT\tWT\n");
    printf("----------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i, bt[i], compt[i], tat[i], wt[i]);
    }
    printf("----------------------------------\n");
    printf("Average WT = %.2f\tAverage TAT = %.2f\n", avgwt, avgtat);
    printf("----------------------------------\n");

    return 0;
}
