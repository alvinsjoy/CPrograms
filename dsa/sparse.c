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
		int compactMatrix[size][3];
    	int k=0;
    	for (int i=0;i<row;i++)
        	for (int j=0;j<col;j++)
            	if (a[i][j]!=0)
            	{
                	compactMatrix[k][0]=i;
                	compactMatrix[k][1]=j;
                	compactMatrix[k][2]=a[i][j];
                	k++;
            	}
 
    	for (int i=0;i<size;i++)
    	{
        	for (int j=0;j<3;j++)
            	printf("%d ",compactMatrix[i][j]);
        	printf("\n");
    	}
	}
	else
		printf("Not a sparse matrix");	
}
