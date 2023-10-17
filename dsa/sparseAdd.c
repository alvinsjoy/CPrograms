#include <stdio.h>
void main()
{
	int a[50][50],b[50][50],sum[50][50],row,col,s1=0,s2=0;
	printf("Enter the number of rows:");
	scanf("%d",&row);
	printf("Enter the number of columns:");
	scanf("%d",&col);
	printf("Enter the elements of matrix 1:");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the elements of matrix 2:");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(a[i][j]!=0)
            	s1++;
            if(b[i][j]!=0)
            	s2++;
		}
	}
	if(s1>=(row*col/2) && s2>=(row*col/2))
	{
		printf("Both are sparse matrices\n");
		int mat1[s1][3],mat2[s2][3];
    	int k=0;
    	for (int i=0;i<row;i++)
        	for (int j=0;j<col;j++)
            	if (a[i][j]!=0)
            	{
                	mat1[k][0]=i;
                	mat1[k][1]=j;
                	mat1[k][2]=a[i][j];
                	k++;
            	}
        for (int i=0;i<row;i++)
        	for (int j=0;j<col;j++)
            	if (b[i][j]!=0)
            	{
                	mat2[k][0]=i;
                	mat2[k][1]=j;
                	mat2[k][2]=a[i][j];
                	k++;
            	}
 		printf("Sparse matrix 1:\n");
    	for (int i=0;i<s1;i++)
    	{
        	for (int j=0;j<3;j++)
            	printf("%d ",mat1[i][j]);
        	printf("\n");
    	}
    	printf("Sparse matrix 2:\n");
    	for (int i=0;i<s2;i++)
    	{
        	for (int j=0;j<3;j++)
            	printf("%d ",mat2[i][j]);
        	printf("\n");
    	}
    	int count=1;
    	for(i=1;i<s1;i++)
		{
    		for(j=1;j<s2;j++) 
        	{
        		if ((a[i][1]==b[j][1])&&(a[i][2]==b[j][2])) 
        		{
        			sum[count][1]=a[i][1]; 
        			sum[count][2]=a[i][2];
        			sum[count][3]=a[i][3]+b[j][3];
        			a[i][3]=0; 
        			b[j][3]=0;
        			count++;
        		}
        	}
		}
	}
	else
		printf("Not a sparse matrix");
}

