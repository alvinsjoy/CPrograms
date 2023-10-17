#include <stdio.h>
void main()
{
	int a[50][50],row,col,size=0;
	printf("Enter the number of rows:");
	scanf("%d",&row);
	printf("Enter the number of columns:");
	scanf("%d",&col);
	printf("Enter the elements:");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(a[i][j]!=0)
            	size++;
		}
	}
	if(size>=(row*col/2))
	{
		printf("It is a sparse matrix\n");
		int compactMatrix[3][size];
    	int k=0;
    	for (int i=0;i<row;i++)
        	for (int j=0;j<col;j++)
            	if (a[i][j]!=0)
            	{
                	compactMatrix[0][k]=i;
                	compactMatrix[1][k]=j;
                	compactMatrix[2][k]=a[i][j];
                	k++;
            	}
 
    	for (int i=0;i<3;i++)
    	{
        	for (int j=0;j<size;j++)
            	printf("%d ",compactMatrix[i][j]);
        	printf("\n");
    	}
	}
	else
		printf("\nNot a sparse matrix");	
}
