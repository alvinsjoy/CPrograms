#include <stdio.h>
int linearSearch(int a[50], int n)
{
	int i, flag, k;
	printf("\nEnter the element to be searched:");
	scanf("%d", &k);
	for (i = 0; i < n; i++)
	{
		if (a[i] == k)
		{
			flag = 1;
			break;
		}
		else
			flag = 0;
	}
	if (flag == 1)
		printf("\nElement found at %d", i + 1);
	else
		printf("\nElement not found");
}
int binarySearch(int a[50], int high)
{
	int x, low = 0;
	printf("\nEnter the element to be searched:");
	scanf("%d", &x);
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}
void selectionSort(int a[], int n)
{
	int i, j, min;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
		{
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
	}
	printf("\nSorted array:");
	for (i = 0; i < n; i++)
		printf("%d,", a[i]);
}
void bubbleSort(int a[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	printf("\nSorted array:");
	for (i = 0; i < n; i++)
		printf("%d,", a[i]);
}
void main()
{
	int arr[50], n, i, ch;
	printf("\nEnter the limit:");
	scanf("%d", &n);
	printf("\nEnter the elements:");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("\n1.Linear Search\n2.Binary Search\n3.Selection Sort\n4.Bubble Sort\nEnter your choice:");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		linearSearch(arr, n);
		break;
	case 2:
		binarySearch(arr, n);
		break;
	case 3:
		selectionSort(arr, n);
		break;
	case 4:
		bubbleSort(arr, n);
		break;
	default:
		printf("Invalid Entry");
		break;
	}
}
