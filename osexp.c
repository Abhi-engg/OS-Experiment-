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