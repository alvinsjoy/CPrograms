#include <stdio.h>
struct polynomial
{
    int pow;
    int coeff;
} p1[50], p2[50], p3[50];
int add(struct polynomial p1[50], struct polynomial p2[50], int len1, int len2, struct polynomial p3[50])
{
    int i = 0, j = 0, k = 0;
    while (i < len1 && j < len2)
    {
        if (p1[i].pow == p2[j].pow)
        {
            p3[k].coeff = p1[i].coeff + p2[j].coeff;
            p3[k].pow = p1[i].pow;
            i++;
            j++;
            k++;
        }
        else if (p1[i].pow > p2[j].pow)
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].pow = p1[i].pow;
            i++;
            k++;
        }
        else
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].pow = p2[j].pow;
            j++;
            k++;
        }
    }
    while (i < len1)
    {
        p3[k].coeff = p1[i].coeff;
        p3[k].pow = p1[i].pow;
        i++;
        k++;
    }
    while (j < len2)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].pow = p2[j].pow;
        j++;
        k++;
    }

    return (k);
}
void display(struct polynomial p[50], int term)
{
    int k;
    for (k = 0; k < term - 1; k++)
        printf("%d(x^%d)+", p[k].coeff, p[k].pow);
    printf("%d(x^%d)", p[term - 1].coeff, p[term - 1].pow);
}

void main()
{
    int i, len1, len2, len3;
    printf("\nEnter the number of terms of the polynomial 1:");
    scanf("%d", &len1);
    printf("\nEnter the polynomial 1:");
    for (i = 0; i < len1; i++)
    {
        printf("\nEnter the power of the %d th term:", i + 1);
        scanf("%d", &p1[i].pow);
        printf("\nEnter the coefficient of the %d th term:", i + 1);
        scanf("%d", &p1[i].coeff);
    }
    printf("\nEnter the number of terms of the polynomial 2:");
    scanf("%d", &len2);
    printf("\nEnter the polynomial 2:");
    for (i = 0; i < len2; i++)
    {
        printf("\nEnter the power of the %d th term:", i + 1);
        scanf("%d", &p2[i].pow);
        printf("\nEnter the coefficient of the %d th term:", i + 1);
        scanf("%d", &p2[i].coeff);
    }
    len3 = add(p1, p2, len1, len2, p3);
    printf("\n Resultant polynomial after addition : ");
    display(p3, len3);
}
