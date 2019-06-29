#include<stdio.h>
void main()
{
	int Pid[10],AT[10],BT[10],bt[10],CT[10],WT[10],TAT[10],TQ,i,j,n,l,temp;
	float sum=0,sum1=0;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
	printf("Enter the time quantum\n");
	scanf("%d",&TQ);
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
	for(i=0;i<n;i++)                  //sorting according to arrival times.
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
	for(i=0;i<n;i++)                //Taking temporary burst time array.
	{
		bt[i]=BT[i];
	}
	l=AT[0];                              //Taking count variable as l.
	for(i=0;i<n;)                         //Executes for n times.
	{
	    for(j=0;j<n;j++)
	    {
	    	if(BT[j]!=0 && AT[j]<=l)  //checks if BT is not 0 & whether process has arrived.
	    	{                         //if BT=0; => CT is calculated for that process.     
	    		if(TQ<=BT[j])       
	    		{
	    			l=l+TQ;                 // incrementing l , TQ times.
	    			CT[j]=l;               // assigning CT with l.
	    			BT[j]=BT[j]-TQ;       // decrementing BT , TQ times.
				}
				else                     // if BT < TQ
				{
					l=l+BT[j];          // incrementing l, BT times.
					CT[j]=l;           // assigning CT with l.
					BT[j]=0;          //decrementing BT to 0.
				}
				if(BT[j]==0) i++;    //i increments when burst time of a process is over.
			}
		}
	}
	for(i=0;i<n;i++)                       // calculating TAT & WT.
	{
		TAT[i]=CT[i]-AT[i];
		WT[i]=TAT[i]-bt[i];
	}
	printf("Pid\tAT\tBT\tCT\tTAT\tWT\n"); //Printing values.
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",Pid[i],AT[i],bt[i],CT[i],TAT[i],WT[i]);
	}
	for(i=0;i<n;i++)                     //calculating average.
	{
	    sum=sum+TAT[i];
	    sum1=sum1+WT[i];
	}
	printf("The average turn around time is: %f \n",sum/n);
	printf("The average waiting time is: %f ",sum1/n);
}
