#include<stdio.h>
void selectionSort(int arr[100], int n){
    for(int i = 0; i < n-1; i++){
        int min = arr[i];
        int pos = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[pos]){
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
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
    selectionSort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}