#include<stdio.h>
int Partition(int arr[],int n){
    int low=0,high=n-1;
    while (low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==0){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return low;
}
int main(){
    int n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements (0s then 1s):\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int index=Partition(arr, n);
    if(index==n){
        printf("All elements are 0.\n");
    }else if(index==0){
        printf("All elements are 1.\n");
    }else{
        printf("Partition point is at index %d\n",index);
    }
    return 0;
}