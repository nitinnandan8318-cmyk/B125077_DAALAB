#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int st;
    int end;
}list;
int compare(const void *a, const void *b){
    list *x = (list *)a;
    list *y = (list *)b;
    return x->st - y->st;
}
int main(){
    int n;
    printf("enter number of pairs : ");
    scanf("%d",&n);
    list *arr = (list *)malloc(n *sizeof(list));
    list *result = (list *)malloc(n *sizeof(list));
    for(int i=0;i<n;i++){
        printf("enter start interval : ");
        scanf("%d",&arr[i].st);
        printf("enter end interval : ");
        scanf("%d",&arr[i].end);
    }
    qsort(arr,n,sizeof(list),compare);
    result[0]=arr[0];
    int c=1;
    for(int i=1;i<n;i++){
        if(result[c-1].end >= arr[i].st){
            if(result[c-1].end < arr[i].end){
                result[c-1].end = arr[i].end;
            }
        }else{
            result[c]= arr[i];
            c++;
        }
    }
    printf("\nmerged intervals\n");
    for(int i=0;i<c;i++){
        printf("(%d,%d)\t",result[i].st,result[i].end);
    }
    free(arr);
    free(result);
    return 0;
}