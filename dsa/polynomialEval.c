#include <stdio.h>
#include<math.h>
struct poly{
	int coeff;
	int pow;
}a[50];
void main()
	{	
        int n,x,sum=0;
		printf("\nEnter the number of elements:");
		scanf("%d",&n);
			for(int i=0;i<n;i++)
            {   
                printf("\nEnter the power of term %d: ",i+1);
                scanf("%d",&a[i].pow);
				printf("\nEnter coefficient of x of the term %d: ",i+1);
				scanf("%d",&a[i].coeff);
			}
				for(int i=0;i<n;i++){
					printf("%d x^%d\t",a[i].coeff,a[i].pow);
				}
				
					
					printf("\nEnter the value of x:");
					scanf("%d",&x);
					
					for(int i=0;i<n;i++){
						sum+=a[i].coeff*pow(x,a[i].pow);
					};
					printf("Sum: %d",sum);
	}