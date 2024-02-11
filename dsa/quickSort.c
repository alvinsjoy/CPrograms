#include <stdio.h>
int temp, pivotIndex;
int partition(int arr[], int lb, int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start < end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < end){
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    return end; //end is the pivotIndex
}
void quickSort(int arr[], int lb, int ub){
    if(lb < ub){
        pivotIndex = partition(arr, lb, ub);
        quickSort(arr, lb, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, ub);
    }
}
void main(){
    int n, arr[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}