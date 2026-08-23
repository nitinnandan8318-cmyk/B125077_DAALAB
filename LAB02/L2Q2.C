#include<stdio.h>
void merge(int arr[],int st,int mid1,int mid2,int end){
    int brr[end-st+1];
    int i=st,j=mid1+1,k=mid2+1,l=0;
    while(i<=mid1 && j<=mid2 && k<=end){
        if(arr[i]<=arr[j] && arr[i]<=arr[k])
            brr[l++]=arr[i++];
        else if(arr[j]<=arr[i] && arr[j]<=arr[k])
            brr[l++]=arr[j++];
        else
            brr[l++]=arr[k++];
    }
    while(i<=mid1 && j<=mid2){
        if(arr[i]<=arr[j])
            brr[l++]=arr[i++];
        else
            brr[l++]=arr[j++];
    }
    while(i<=mid1 && k<=end){
        if(arr[i]<=arr[k])
            brr[l++]=arr[i++];
        else
            brr[l++]=arr[k++];
    }
    while(k<=end && j<=mid2){
        if(arr[k]<=arr[j])
            brr[l++]=arr[k++];
        else
            brr[l++]=arr[j++];
    }
    while(i<=mid1)
        brr[l++]=arr[i++];
    while(j<=mid2)
        brr[l++]=arr[j++];
    while(k<=end)
        brr[l++]=arr[k++];
    for(int i=st,l=0;i<=end;i++,l++)
        arr[i]=brr[l];  
}
void mergesort(int arr[],int st,int end){
    if(st>=end){
        return;
    }
    int mid1 = st+(end-st)/3;
    int mid2 = st+2*(end-st)/3;
    mergesort(arr,st,mid1);
    mergesort(arr,mid1+1,mid2);
    mergesort(arr,mid2+1,end);
    merge(arr,st,mid1,mid2,end);
}
int main(){
    int n;
    printf("enter size of an array:");
    scanf("%d",&n);
    int arr[n];
    printf("\nenter elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("\nafter sorting\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
// The wrost-case running time of this modified merge sort is O(n log(base 3)n).