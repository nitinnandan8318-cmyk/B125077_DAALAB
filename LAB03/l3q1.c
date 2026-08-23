#include<stdio.h>
#include<stdlib.h>
int binarystep=0;
int ternarystep=0;
int *generatearray(int n){
    int *arr = (int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    return arr;
}
int binarysearch(int arr[],int st,int end,int x){
    binarystep += 2;
    if(st==end){
        if(x==arr[st])
            return x;
        else
            return -1;
    }else{
        int mid = (st+end)/2;
        if(x<=arr[mid])
            return binarysearch(arr,st,mid,x);
        else
            return binarysearch(arr,mid+1,end,x);
    }
}
int ternarysearch(int arr[],int st,int end,int x){
    ternarystep += 4;
    if(st==end){
        if(x==arr[st])
            return x;
        else
            return -1;
    }else{
        int mid1 = st+(end-st)/3;
        int mid2 = end-(end-st)/3;
        if(x<=arr[mid1])
            return ternarysearch(arr,st,mid1,x);
        else if(x>arr[mid1] && x<=arr[mid2])
            return ternarysearch(arr,mid1+1,mid2,x);
        else
            return ternarysearch(arr,mid2+1,end,x);
    }
}
int main(){
    int n,x;
    printf("enter number of elements:");
    scanf("%d",&n);
    int *arr = generatearray(n);
    printf("enter element:");
    scanf("%d",&x);
    binarysearch(arr,0,n-1,x);
    ternarysearch(arr,0,n-1,x);
    printf("\nbinary search step count:%d\nternary steps count:%d",binarystep,ternarystep);
    free(arr);
    return 0;
}