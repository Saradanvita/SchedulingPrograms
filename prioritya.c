#include<stdio.h>
void main()
{
	int Pid[10],AT[10],BT[10],PRI[10],CT[10],TAT[10],WT[10],i,j,n,temp,k,l,m,p,ideal;
	float sum=0,sum1=0;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	printf("Enter the Pids\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&Pid[i]);
	}
	printf("Enter the arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&AT[i]);
	}
	printf("Enter the burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&BT[i]);
	}
	printf("Enter the priorities\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&PRI[i]);
    }
	CT[0]=BT[0];
	ideal=AT[0];                                 //CPU waits till first process arrives
	for(i=1;i<n;i++)
	{
		k=0;p=i;
		while(AT[p]<=CT[i-1] && p<n)             //checks if process arrived.
		{
			k++;p++;                             //no. of processes that have arrived.
		}
		j=k+i-1;                                //index of the last process that has arrived.
		for(l=i;l<=j;l++)
		{
			for(m=i;m<=j-1;m++)
			{
				if(PRI[m]>PRI[m+1])             //sorting by highest priority.
				{
					temp=PRI[m];PRI[m]=PRI[m+1];PRI[m+1]=temp;
					temp=BT[m];BT[m]=BT[m+1];BT[m+1]=temp;
					temp=AT[m];AT[m]=AT[m+1];AT[m+1]=temp;
					temp=Pid[m];Pid[m]=Pid[m+1];Pid[m+1]=temp;
				}
			}
		}
		if(CT[i-1]<AT[i])                        //checks if CPU is idle.
		{
			ideal=ideal+AT[i]-CT[i-1];
			CT[i]=CT[i-1]+BT[i]+(AT[i]-CT[i-1]); //CT calculation if CPU is idle.
		}
		else                                     //CT calculation if CPU is not idle.
		{
			CT[i]=CT[i-1]+BT[i];
		}
	}
	for(i=0;i<n;i++)                            //calculating TAT & BT 
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-BT[i];
	}
	printf("Pid\tAT\tBT\tPRI\tCT\tTAT\tWT\n"); //printing values.
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",Pid[i],AT[i],BT[i],PRI[i],CT[i],TAT[i],WT[i]);
	}
	for(i=0;i<n;i++)                          //calculating average.
	{
	    sum=sum+TAT[i];
	    sum1=sum1+WT[i];
	}
	printf("The average turn around time is: %f \n",sum/n);
	printf("The average waiting time is: %f ",sum1/n);
}
