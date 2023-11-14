#include<stdio.h>
void main()
{
	int u1,u2,c[100][3];
	printf("Enter the number of non zero elements of first matrix:");
	scanf("%d",&u1);
	int a[u1][3],b[u1][3];
	printf("\nEnter the sparse representation of first matrix:");
	for(int i=0;i<u1;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the number of non zero elements of second matrix:");
	scanf("%d",&u2);
	printf("Enter the sparse representation of first matrix:");
	for(int i=0;i<u2;i++)
	{
		for(int j=0;j<3;j++)
			scanf("%d",&b[i][j]);
	}
	printf("\nMatrix 1:");
	printf("\nRow\tColumn\tValue\n");
    for (int i=0;i<u1;i++)
    {
        for (int j=0;j<3;j++)
        	printf("%d\t",a[i][j]);
        printf("\n");
    }
	printf("\nMatrix 2:");
	printf("\nRow\tColumn\tValue\n");
	for (int i=0;i<u2;i++)
    {
        for (int j=0;j<3;j++)
        	printf("%d\t",b[i][j]);
        printf("\n");
    }
    int k=0,i=0,j=0;
    while (i<u1 && j<u2)
    {
        if (a[i][0]<b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1]))
        {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            i++;
        }
        else if (a[i][0]>b[j][0] || (a[i][0]==b[j][0] && a[i][1]>b[j][1]))
        {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            j++;
        }
        else
        {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2]+b[j][2];
            i++;
            j++;
        }
        k++;
    }
    while (i<u1)
    {
        c[k][0]=a[i][0];
        c[k][1]=a[i][1];
        c[k][2]=a[i][2];
        i++;
        k++;
    }
    while (j<u2)
    {
        c[k][0]=b[j][0];
        c[k][1]=b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    printf("\nRow\tColumn\tValue\n");
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<3;j++)
            printf("%d\t",c[i][j]);
        printf("\n");
    }    
}
