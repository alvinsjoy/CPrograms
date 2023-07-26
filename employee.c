#include <stdio.h>
struct employee
{
 	char name[30];
 	int id;
 	int salary;
}emp[50];
void main()
{
	int n,i;
	printf("\nEnter the number of employees:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the employee name:");
		scanf("%s",emp[i].name);
		printf("\nEnter id:");
		scanf("%d",&emp[i].id);
		printf("\nEnter Salary:");
		scanf("%d",&emp[i].salary);
	}
	printf("Name\t ID\t Salary\n");
	for(i=0;i<n;i++)
		printf("%s\t %d\t %d\n",emp[i].name,emp[i].id,emp[i].salary);
}
