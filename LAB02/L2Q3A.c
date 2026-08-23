#include<stdio.h>
void merge(int size1,int size2,int brr[],int arr[],int temp[]){
    int i=0,j=0,k=0;
    while(i<size1 && j<size2){
        if(brr[i]<=arr[j])
            temp[k++]=brr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<size1)
        temp[k++]=brr[i++];
    while (j<size2)
        temp[k++]=arr[j++];    
}
void sort(int n,int k,int arr[k][n]){
    int temp[k*n];
    int brr[k*n];
    int size=n;
    for(int i=0;i<n;i++){
        brr[i]=arr[0][i];
    }
    for(int i=1;i<k;i++){
        merge(size,n,brr,arr[i],temp);
        size += n;
        for(int j=0;j<size;j++)
            brr[j]=temp[j];
    }
    printf("\nafter sorting\n");
    for(int i=0;i<size;i++)
        printf("%d\t",brr[i]);
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
    sort(n,k,arr);
    return 0;
}
//Worst-case order of growth is Θ(nk^2)