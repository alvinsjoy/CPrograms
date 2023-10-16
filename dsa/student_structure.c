/*
Write a program to create a student structure, input marks for 5 subjects, sort the structure using bubble sort to find out the sorted marks.
Alvin Joy
CS3B
*/
#include <stdio.h>
struct student
{
	int sub1;
	int sub2;
	int sub3;
	int sub4;
	int sub5;
	long int sum;
}s[60];
void main()
{
	int n,i,j;
	printf("Enter the number of students:");
	scanf("%d",&n);
	printf("\nEnter the marks:");
	for(i=0;i<n;i++)
	{
		printf("\nEnter the marks of subject 1:");
		scanf("%d",&s[i].sub1);
		printf("\nEnter the marks of subject 2:");
		scanf("%d",&s[i].sub2);
		printf("\nEnter the marks of subject 3:");
		scanf("%d",&s[i].sub3);
		printf("\nEnter the marks of subject 4:");
		scanf("%d",&s[i].sub4);
		printf("\nEnter the marks of subject 5:");
		scanf("%d",&s[i].sub5);
		s[i].sum=s[i].sub1+s[i].sub2+s[i].sub3+s[i].sub4+s[i].sub5;
	}
	for(i=0;i<n-1;i++) 
		{
        	for(j=0;j<n-i-1;j++)
        	{
            	if(s[j].sum>s[j+1].sum)
            	{
                	int temp=s[j].sum;
                	s[j].sum=s[j+1].sum;
                	s[j+1].sum=temp;
            	}
        	}
    	}
    	printf("\nSorted array:");
    	for (i=0;i<n;i++)
    		printf("%d,",s[i].sum);
}
