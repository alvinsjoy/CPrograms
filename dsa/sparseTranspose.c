#include<stdio.h>
void main()
{
	int matrix[100][100];
	int spmatrix[100][3];
	int transpose[100][3];
	int i,j,k,row,col;
	printf("Enter the order of sparse matrix:\n");
	scanf("%d%d",&row,&col);
	printf("Enter the elements of the sparse matrix:\n");
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			scanf("%d",&matrix[i][j]);
	}
	k=1;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(matrix[i][j]!=0)
			{
				spmatrix[k][0]=i;
				spmatrix[k][1]=j;
				spmatrix[k][2]=matrix[i][j];
				k++;
			}
		}
	}
	spmatrix[0][0]=row;
	spmatrix[0][1]=col;
	spmatrix[0][2]=k-1;

	printf("Elements of the sparse matrix:\n");
	for(i=0;i<=spmatrix[0][2];i++)
	{
		for(j=0;j<3;j++)
			printf("%d\t",spmatrix[i][j]);
		printf("\n");
	}
	transpose[0][0]=spmatrix[0][1];
	transpose[0][1]=spmatrix[0][0];
	transpose[0][2]=spmatrix[0][2];
	k=1;
	for(i=0;i<spmatrix[0][1];i++)
	{
		for(j=0;j<=spmatrix[0][2];j++)
		{
			if(spmatrix[j][1]==i)
			{
				transpose[k][0]=spmatrix[j][1];
				transpose[k][1]=spmatrix[j][0];
				transpose[k][2]=spmatrix[j][2];
				k++;
			}
		}
	}
	printf("Transpose of the sparse matrix\n");
	for(i=0;i<=transpose[0][2];i++)
	{
	for(j=0;j<3;j++)
		printf("%d\t",transpose[i][j]);
	printf("\n");
	}
}
