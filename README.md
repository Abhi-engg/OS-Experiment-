EXPERIMENT NO:-5

AIM: - Write a program to implement CPU Scheduling algorithms like FCFS &amp; SJF.
THEORY:-
1. FIRST-COME, FIRST-SERVE SCHEDULING (FCFS):
In this, which process enter the ready queue first is served first. The OS maintains DS that is
ready queue. It is the simplest CPU scheduling algorithm. If a process request the CPU then it is
loaded into the ready queue, which process is the head of the ready queue, connect the CPU to
that process.
Algorithm for FCFS scheduling:
Step 1: Start the process
Step 2: Accept the number of processes in the ready Queue
Step 3: For each process in the ready Q, assign the process id and accept the CPU burst time
Step 4: Set the waiting of the first process as ‘0’ and its burst time as its turn around time
Step 5: for each process in the Ready Q calculate
(c) Waiting time for process(n)=waiting time of process (n-1) + Bursttime of process(n-1)
(d) Turn around time for Process(n)= waiting time of Process(n)+ Burst time for process(n)
Step 6: Calculate
(e) Average waiting time = Total waiting Time / Number of process
(f) Average Turnaround time = Total Turnaround Time / Number of process
Step 7: Stop the process
/* Program to Simulate First Come First Serve CPU Scheduling Algorithm */
#include&lt;stdio.h&gt;
#include&lt;string.h&gt;
int main()
{
int i,j,n,bt[10],compt[10],at[10], wt[10],tat[10];
float sumwt=0.0,sumtat=0.0,avgwt,avgtat;
printf(&quot;Enter number of processes: &quot;);
scanf(&quot;%d&quot;,&amp;n);
printf(&quot;Enter the burst time of %d process\n&quot;, n);
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;bt[i]);
}
printf(&quot;Enter the arrival time of %d process\n&quot;, n);
for(i=0;i&lt;n;i++)
{
scanf(&quot;%d&quot;,&amp;at[i]);
}
compt[0]=bt[0]-at[0];

for(i=1;i&lt;n;i++)
compt[i]=bt[i]+compt[i-1];
for(i=0;i&lt;n;i++)
{
tat[i]=compt[i]-at[i];
wt[i]=tat[i]-bt[i];
sumtat+=tat[i];
sumwt+=wt[i];
}
avgwt=sumwt/n;
avgtat=sumtat/n;
printf(&quot;----------------------------------\n&quot;);
printf(&quot;PN\tBt\tCt\tTat\tWt\n&quot;);
printf(&quot;----------------------------------\n&quot;);
for(i=0;i&lt;n;i++)
{
printf(&quot;%d\t%2d\t%2d\t%2d\t%2d\n&quot;,i,bt[i],compt[i],tat[i],wt[i]);
}
printf(&quot;----------------------------------\n&quot;);
printf(&quot; Avgwt = %.2f\tAvgtat = %.2f\n&quot;,avgwt,avgtat);
printf(&quot;-----------------------------------\n&quot;);
return 0;
}
