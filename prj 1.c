#include<stdio.h>
void main()
{
    int at[10],bt[10],p[20],wt[10],tat[10],i,j,n,total=0,pos,temp,z;
    float avg_wt,avg_tat;
    double wait_time = 0,turnaround_time=0;
    int  tmp[10] ,end;
    int  smallest, count = 0, time;

    float average_waiting_time, average_turnaround_time;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
    printf("\nEnter Arrival Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;           //contains process number
    }
    //sorting burst time in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        temp=at[i];
        at[i]=at[pos];
        at[pos]=temp;
    }

    wt[0]=0;            //waiting time for first process will be zero

    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=(float)total/n;      //average waiting time
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time \t Arrival Time ");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d\t\t \t  %d",p[i],bt[i],wt[i],tat[i],at[i]);
    }


printf("\n 1- preemptive algo 2-  Nonpreemptive algo \n ");
printf("\n enter the value: ");
scanf("%d",&z);
if(z==1)
{
      bt[9] = 9999;
      for(time = 0; count != n; time++)
      {
            smallest = 9;
            for(i = 0; i < n; i++)
            {
                  if(at[i] <= time && bt[i] <bt[smallest] && bt[i] > 0)
                  {
                        smallest = i;
                  }
            }
            bt[smallest]--;
            if(bt[smallest] == 0)
            {
                  count++;
                  end = time + 1;
                  printf("%d ",end);
                  wait_time= wait_time + end - at[smallest] - tmp[smallest];
                  turnaround_time= turnaround_time + end - at[smallest];
            }

        }

      avg_wt = wait_time / n;
      avg_tat = turnaround_time / n;
      printf("\n\nAverage Waiting Time:\t%lf\n", avg_wt);
      printf("Average Turnaround Time:\t%lf\n", tat);
}
else if(z==2)
{
printf("\n \n non preemptive");



    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
else
{
printf("  wrong input");
}
}
