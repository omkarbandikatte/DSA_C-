#include<stdio.h>
#include<conio.h>

int main() {
    int n;
    int a[20];
    printf("Enter the number of elements you want in an array:- ");
    scanf("%d",&n);
    printf("Enter the elements in an array:- \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("The elements in an Array are:- \n");
    for(int j=0;j<n;j++) {
        printf("%d ", a[j]);
    }
    printf("\n");
    
    for(int i=0;i<n-1;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(a[j] < a[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i) {
            int temp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = temp;
        }
    }

    printf("Sorted Array is:- ");
    for(int k=0;k<n;k++) {
        printf("%d ",a[k]);
    }
}