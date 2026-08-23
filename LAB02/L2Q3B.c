#include<stdio.h>
#include<string.h>
void merge(int arr1[],int arr2[],int temp[],int n1,int n2){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            temp[k++]=arr1[i++];
        }else{
            temp[k++]=arr2[j++];
        }
    }
    while(i<n1){
        temp[k++]=arr1[i++];
    }
    while(j<n2){
        temp[k++]=arr2[j++];
    }
}
void mergesort(int k,int n,int arr[k][n]){
    int brr[k*n];
    int temp[k*n];
    int crr[k*n];
    memset(brr,0,sizeof(brr));
    memset(temp,0,sizeof(temp));
    memset(crr,0,sizeof(crr));
    int i=0;
    int size = 0;
    while(i<k){
        if(i+1 < k){
            merge(arr[i],arr[i+1],temp,n,n);
            if(size==0){
                for(int j=0;j<2*n;j++){
                    brr[j]=temp[j];
                }
                size = 2*n;
            }else{
                merge(temp,brr,crr,2*n,size);
                size += 2*n;
                for(int j=0;j<size;j++){
                    brr[j] =crr[j];
                }
            }
            i += 2;
        }else{
            if(size==0){
                for(int j=0;j<n;j++){
                    brr[j]=arr[i][j];
                }
                size =n;
            }else{
                merge(arr[i],brr,crr,n,size);
                size += n;
                for(int j=0;j<size;j++){
                    brr[j]=crr[j];
                }
            }
            i++;
        }
    }
    printf("\nafter sorting\n");
    for(int l=0;l<size;l++){
        printf("%d\t",brr[l]);
    }
}
int main(){
    int k,n;
    printf("enter number of array:");
    scanf("%d",&k);
    printf("enter size of array:");
    scanf("%d",&n);
    int arr[k][n];
    for(int i=0;i<k;i++){
        printf("\nenter elements of %d array\n",i+1);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    mergesort(k,n,arr);
    return 0;
}