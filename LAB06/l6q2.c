#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int weight;
    int profit;
    float prf_weig;
}rahul;
int compare(const void *a, const void *b){
    rahul *x = (rahul *)a;
    rahul *y = (rahul *)b;
    return x->prf_weig - y->prf_weig;
}
int main(){
    int n,w,p=0;
    printf("enter weight of knapsack : ");
    scanf("%d",&w);
    printf("enter number of object : ");
    scanf("%d",&n);
    rahul *arr = (rahul *)malloc(n *sizeof(rahul));
    for(int i=0;i<n;i++){
        printf("\nenter %d object weight : ",i+1);
        scanf("%d",&arr[i].weight);
        printf("enter profit : ");
        scanf("%d",&arr[i].profit);
        arr[i].prf_weig = arr[i].profit/arr[i].weight;
    }
    qsort(arr,n,sizeof(rahul),compare);
    for(int i=0;i<n;i++){
        if(w>0 && arr[i].weight<w){
            w -= arr[i].weight;
            p += arr[i].profit;
        }
    }
    printf("\nmaximum profit of this knapsack is %d.",p);
    return 0;
}