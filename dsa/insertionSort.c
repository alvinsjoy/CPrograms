#include <stdio.h>
void insertionSort(int arr[], int n){
    int j, key;
    for(int i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ",arr[i]);
}