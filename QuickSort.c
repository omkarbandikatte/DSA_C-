#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int QuickSort(int arr[], int low, int high);
void partition(int arr[], int low, int high);

int main() {
    int i, k, low, high;
    int arr[20];
    printf("Enter the size of an array:- ");
    scanf("%d", &k);
    printf("Enter the elements in an array:- \n");
    for(i = 0; i < k; i++) {
        scanf("%d", &arr[i]);
    }
    printf("The elements in an Array are:- \n");
    for(i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
    low=0;
    high=k-1;
    partition(arr, low, high);
    printf("\nSorted Array is:- ");
    for(i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }
}
void partition(int arr[], int low, int high) {
    int loc;
    if(low<high) {
        loc=QuickSort(arr, low, high);
        partition(arr, low, loc-1);
        partition(arr, loc+1, high);
    }
}

int QuickSort(int arr[], int low, int high) {
    int pivot=arr[low], start=low, end=high, temp;
    while(start<end) {
        while(arr[start]<=pivot) {
            start++;
        }
        while(arr[end]>pivot) {
            end--;
        }
        if(start<end) {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    temp=arr[end];
    arr[end]=arr[low];
    arr[low]=temp;
    return end;
}