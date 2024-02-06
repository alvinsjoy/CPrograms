#include <stdio.h>
#include <stdlib.h>
void merge(int arr[100], int low, int high, int mid){
    int i, j, k, a[100];
    i = low;
    k = low;
    j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            a[k] = arr[i];
            i++;
        }
        else{
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        a[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        a[k] = arr[j];
        j++;
        k++;
    }
    for(i = low; i <= high; i++){
        arr[i] = a[i];
    }
}
void mergeSort(int arr[100], int low, int high){
    if(low < high){
        int mid = (high + low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, high, mid);
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
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}
