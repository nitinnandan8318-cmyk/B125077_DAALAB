#include<stdio.h>
void sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=arr[i];
        int index=i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                index=j;
            }
        }
        arr[index]=arr[i];
        arr[i]=min;
    }
    printf("\nafter sorting\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter %d elements\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,n);
    return 0;
}