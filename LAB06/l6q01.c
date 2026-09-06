#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int max(int arr[],int n){
    int m=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>m)
            m=arr[i];
    }
    return m;
}
void max12(int arr[],int n){
    int m1=arr[0],m2=arr[0];
    if(m2>m1){
        int temp = m2;
        m2 = m1;
        m1 = temp;
    }
    for(int i=0;i<n;i++){
        if(arr[i]>m2){
            m1=arr[i];
            m2=m1;
        }else if(arr[i]>m2){
            m2 = arr[i];
        }
    }
    printf("first maximum number : %d\nsecond maximum nummber : %d\n",m1,m2);
}
float mean(int arr[],int n){
    float s=0,m=0;
    for(int i=0;i<n;i++){
        s += arr[i];
    }
    m = s/n;
    return m;
}
void median(int arr[],int n){

}
int mode(int arr[],int n){
    int m = max(arr,n);
    int mode_index=0,mode_max=0;
    int *brr = (int *)calloc(m,sizeof(int));
    for(int i=0;i<n;i++){
        brr[arr[i]]++;
        if(brr[i]>mode_max)
            mode_index=i;
    }
    return mode_index;
}
int stdrd_deviation(int arr[],int n){
    int m = mean(arr,n);
    int sd=0;
    float s=0,v=0;
    for(int i=0;i<n;i++){
        s += (arr[i]-m)*(arr[i]-m);
    }
    v = s/n;
    sd = sqrt(v);
    return sd;
}
void reverse(int arr[],int n){
    for(int i=0,j=n-1;i<n/2;i++,j--){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    printf("\nreverse array\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
}
void remove_dupli(int arr[],int n){
    int m = max(arr,n);
    int *brr = (int *)calloc(m,sizeof(int));
    int j=0;
    for(int i=0;i<n;i++){
        brr[arr[i]]++;
        if(brr[arr[i]]==1)
            arr[j++]=arr[i];
    }
    arr[j];
    free(brr);
    printf("\nafter excluding duplicate elements\n");
    for(int i=0;i<j;i++){
        printf("%d\t",arr[i]);
    }
}
int main(){
    int n;
    printf("enter number of elements : ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n *sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nmaximum elements : %d\n",max(arr,n));
    max12(arr,n);
    printf("\nmean : %.2f\n",mean(arr,n));
    printf("mode : %d\n",mode(arr,n));
    reverse(arr,n);
    remove_dupli(arr,n);
    free(arr);
    return 0;
}
