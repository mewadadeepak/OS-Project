#include<stdio.h>
#include<conio.h>
int main()
{
    int bt[25],p[25],wt[25],tat[25],pr[25],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("\nEnter Total Number of Process");
    scanf("%d",&n);
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP is %d",i+1);
        printf("Burst Time");
        scanf("%d",&bt[i]);
        printf("Priority");
        scanf("%d",&pr[i]);
        p[i]=i+1; 
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        total+=wt[i];
    }
    avg_wt=total/n;   
    total=0;
    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;
    printf("\nAverage Waiting Time is d",avg_wt);
    printf("\nAverage Turnaround Time is %d\n",avg_tat);
    getch();
    return 0;
}

 
