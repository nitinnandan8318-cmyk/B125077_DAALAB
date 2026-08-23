#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int binarysearch(int arr[],int st,int end,int x){
    if(st==end){
        if(arr[st]==x)
            return st;
        return -1;
    }else{
        int mid = (st+end)/2;
        if(x<=arr[mid])
            return binarysearch(arr,st,mid,x);
        else
        return binarysearch(arr,mid+1,end,x);
    }
}
int ksum(int arr1[],int arr2[],int st,int n,int k,int x,int p){
    if(k==1){
        int t = binarysearch(arr1,st,n-1,x);
        if(t != -1){
            arr2[p]= arr1[t];
            printf("elements: ");
            for(int i=0;i<=p;i++){
                printf("%d\t",arr2[i]);
            }
            printf("\n");
            return 1;
        }
        return 0;

    }
    for(int i=st;i<n;i++){
        arr2[p]=arr1[i];
        if(ksum(arr1,arr2,i,n,k-1,x-arr1[i],p+1))
            return 1;
    }
    return 0;
}
int main(){
    int n,x,k;
    printf("enter number of elements:");
    scanf("%d",&n);
    int *s1 = (int *)malloc(n *sizeof(int));
    printf("\nenter first set elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&s1[i]);
    }
    printf("enter the number to be pair : ");
    scanf("%d",&x);
    printf("enter the nummbers integers to be add : ");
    scanf("%d",&k);
    int *s2 = (int *)malloc(k *sizeof(int));
    qsort(s1, n, sizeof(int), compare);
    if(ksum(s1,s2,0,n,k,x,0))
        printf("combination found \n");
    else
        printf("combination not found.");
    free(s1);
    free(s2);
    return 0;
}
