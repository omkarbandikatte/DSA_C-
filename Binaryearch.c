#include<stdio.h>
#include<conio.h>

int main() {
    int n, val, mid, found=0;
    int a[20];
    printf("Enter the number of elements:- ");
    scanf("%d",&n);
    int low=0, high=n-1;
    printf("Enter the elements:- ");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("Sorted Array:- \n");
    for(int i=0;i<n;i++) {
        printf("%d ",a[i]);
    }

    printf("\n");
    printf("Enter the value you want to Search:- ");
    scanf("%d",&val);

    while(low<=high) {
        mid = (low + high) / 2;
        if(a[mid] == val) {
            found = 1;
            printf("Your value %d is found at index %d",val,mid);
            break;
        } else if(a[mid] < val) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(!found) {
        printf("Your value %d is not found in the array",val);
    }
}