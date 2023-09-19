/*
Write a program to perform array operations
Alvin Joy
CS3B
*/
#include <stdio.h>
void main()
{
	int a[50],b[50],n,ch,i,d,j=0;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d th element:",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter your choice:\n1.Insertion\n2.Deletion\n3.Sort\n4.Search\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the element to be inserted:");
			scanf("%d",&a[n]);
			n+=1;
			printf("\nArray after insertion:");
			for (i=0;i<n;i++)
    			printf("%d,",a[i]);
			break;
		case 2:
			printf("\nEnter the element to be deleted:");
			scanf("%d",&d);
			for(i=0,j=0;i<n;i++)
			{
				if(a[i]!=d)
				{
					b[j]=a[i];
					j++;
				}
			}
			for(i=0;i<j;i++)
				printf("%d,",b[i]);
			break;
		case 3:
			for(i=0;i<n-1;i++) 
			{
        		for(j=0;j<n-i-1;j++)
        		{
            		if(a[j]>a[j+1])
            		{
                		int temp=a[j];
                		a[j]=a[j+1];
                		a[j+1]=temp;
            		}
        		}
    		}
    		printf("\nSorted array:");
    		for (i=0;i<n;i++)
    			printf("%d,",a[i]);	
    		break;
    	case 4:
    		printf("\nEnter the element to be searched:");
			scanf("%d",&d);
			for(i=0;i<n;i++)
			{
				if(a[i]==d)
					j=1;
			}
			if(j==1)
				printf("Element found at %d",i);
			else
				printf("Not found");
			break;
		default:
			printf("Invalid Entry");
			break;
	}
}
