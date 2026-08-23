#include<stdio.h>
void minmax(int arr[],int st,int end,int *min,int *max){
    int min1,min2,max1,max2;
    if(st==end){
        *min = arr[st];
        *max = arr[st];
        return;
    }else if(end == st+1){
        if(arr[st] > arr[end]){
            *min = arr[end];
            *max = arr[st];
        }else if(arr[st]<arr[end]){
            *min = arr[st];
            *max = arr[end];
        }else{
            *min = arr[st];
            *max = arr[st];
        }
        return;
    }
    int mid=(end+st)/2;
    minmax(arr,st,mid,&min1,&max1);
    minmax(arr,mid+1,end,&min2,&max2);
    if(min1<min2)
        *min = min1;
    else
        *min = min2;
    if(max1>max2)
        *max = max1;
    else
        *max = max2;
    
}
int main(){
    int n,min,max;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter %d elements\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    minmax(arr,0,n-1,&min,&max);
    printf("maximun number : %d\nminimum number : %d",max,min);
    return 0;
}