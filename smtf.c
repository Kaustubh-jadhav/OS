#include<stdio.h>
#include<stdlib.h>
int main()
{
	int q[100],i,n,seek=0,head,count=0;
	printf("\n Enter the number of request: ");
	scanf("%d",&n);
	printf("\n Enter the request sequence: ");
	for(i=0;i<n;i++)
		scanf("%d",&q[i]);
	printf("\n Enter initial head position: ");
	scanf("%d",&head);
	printf("Sequence of head movement:\n");
	while(count!=n)
	{
		int min=1000,diff,index;
		for(i=0;i<n;i++)
		{
			diff=abs(q[i]-head);
			if(min>=diff)
			{
				min=diff;
				index=i;
			}
		}
		seek+=min;
		head=q[index];
		printf("%d\n",q[index]);
		q[index]=1000;
		count++;
	}
	printf("Total head movement is:%d",seek);
	return 0;
}