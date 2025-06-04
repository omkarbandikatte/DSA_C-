#include<stdio.h>
#include<conio.h>

int main() {
    int n, val, found=0;
    int a[20];
    printf("Enter the numbeer of elements:- ");
    scanf("%d",&n);
    printf("Enter the Elements:- \n");
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter the valu you want to Search:- ");
    scanf("%d",&val);

    for(int j=0;j<n;j++) {
        if(a[j]==val){
            found=1;
            printf("Your value %d is found at index %d",val,j);
        }
    }
    if(found==0) {
        printf("Your value %d is not found in the array",val);
    }
}