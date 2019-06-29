#include<stdio.h>
void main()
{
	int Pid[10],AT[10],BT[10],bt[10],CT[10],WT[10],TAT[10],i,j,k,l,m,n,p,temp,x;
	float sum=0,sum1=0;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
	printf("Enter the Pids\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Pid[i]);
	}
	printf("Enter the arrival times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&AT[i]);
	}
	printf("Enter the burst times\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&BT[i]);
	}
	for(i=0;i<n;i++)                         //sorting by shortest arrival time.
	{
		for(j=0;j<n-1;j++)
		{
			if(AT[j]>AT[j+1])
			{
				temp=AT[j];AT[j]=AT[j+1];AT[j+1]=temp;
				temp=BT[j];BT[j]=BT[j+1];BT[j+1]=temp;
			    temp=Pid[j];Pid[j]=Pid[j+1];Pid[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)                        //Taking temporary burst time array.
	{
		bt[i]=BT[i];
	}
	x=0;                                    //count variable 
	CT[x]=0;
	for(i=0;i<=AT[n-1];i++)                //executes till all processes have arrived
	{
		k=0;p=i;
		while(AT[p]<=CT[x] && p<n && x<n) //checking if process has arrived.
		{
			k++;                          //no. of processes that have arrived.
			p++;
			if(BT[x]==0)
			{  
			    x++;                      //increments only when BT of a process is over.
				CT[x]=CT[x-1];            //entering previous values.
			}
		}
		j=k+i-1;                          //index of the last process that has arrived.
		for(l=x;l<=j;l++)                 //sorting the arrived processes.
		{
			for(m=x;m<=j-1;m++)
			{
				if(BT[m]>BT[m+1])         //sorting by shortest BT.
				{
					temp=bt[m];bt[m]=bt[m+1];bt[m+1]=temp;
					temp=BT[m];BT[m]=BT[m+1];BT[m+1]=temp;
					temp=Pid[m];Pid[m]=Pid[m+1];Pid[m+1]=temp;
					temp=AT[m];AT[m]=AT[m+1];AT[m+1]=temp;
				}
			}
		}
		CT[x]++;                         //CT increments as BT decrements.
	 	BT[x]--;
	}
	CT[x]=CT[x]+BT[x];                  //After all processes have arrived 
	for(i=x+1;i<n;i++)                  //calculating as per shortest job first.
	{
		CT[i]=BT[i]+CT[i-1];
	}
    for(i=0;i<n;i++)                     //Calculating TAT & BT.
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-bt[i];
	}
	printf("Pid\tAT\tBT\tCT\tTAT\tWT\n");  //Printing values.
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",Pid[i],AT[i],bt[i],CT[i],TAT[i],WT[i]);
	}
	for(i=0;i<n;i++)                       //calculating average.
	{
	    sum=sum+TAT[i];
	    sum1=sum1+WT[i];
	}
	printf("The average turn around time is: %f \n",sum/n);
	printf("The average waiting time is: %f ",sum1/n);
}
