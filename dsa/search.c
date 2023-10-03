#include <stdio.h>
int linearSearch(int a[50],int n)
{
	int i,flag,k;
	printf("\nEnter the element to be searched:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			flag=1;
			break;
		}
		else
			flag=0;
	}
	if(flag==1)
		printf("\nElement found at %d",i+1);
	else
		printf("\nElement not found");
}
int binarySearch(int a[50],int n)
{
	
void main()
{
	int arr[50],n,i,ch;
	printf("\nEnter the limit:");
	scanf("%d",&n);
	printf("\nEnter the elements:");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	printf("\n1.Linear Search\n2.Binary Search\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			linearSearch(arr,n);
		case 2:
			binarySearch(arr,n);
		default:
			printf("Invalid Entry");
	}
}
