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
int main(){
    int n,x;
    printf("enter number of elements:");
    scanf("%d",&n);
    int *s1 = (int *)malloc(n *sizeof(int));
    int *s2 = (int *)malloc(n *sizeof(int));
    printf("\nenter first set elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&s1[i]);
    }
    printf("\nenter second set elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&s2[i]);
    }
    printf("enter the number to be pair : ");
    scanf("%d",&x);
    qsort(s2, n, sizeof(int), compare);
    for(int i=0;i<n;i++){
        int t = binarysearch(s2,0,n-1,(x-s1[i]));
        if(t  != -1)
            printf("paired found = %d\t%d\n",s1[i],s2[t]);
    }
    free(s1);
    free(s2);
    return 0;
}
