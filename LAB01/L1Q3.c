#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int sortbefore(int arr[], int n){
    int comps=0;
    for(int i=0;i<n-1;i++){
        int swapped=0;
        for(int j=0;j<n-i-1;j++){
            comps++;
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j + 1];
                arr[j+1]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
    }
    return comps;
}
int sortalwys(int arr[], int n){
    int comps=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            comps++;
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return comps;
}
int main(){
    int n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int a[n], b[n];
    srand(time(NULL));
    printf("\nRandom Array:\n");
    for(int i=0;i<n;i++){
        a[i] = rand()%100;
        b[i] = a[i];
        printf("%d\t",a[i]);
    }
    int before = sortbefore(a,n);
    int always = sortalwys(b,n);
    printf("\n\nComparisons:\n");
    printf("sorted befoe the (n-1)th pass : %d\n",before);
    printf("completed the (n-1)th pass : %d\n",always);
    return 0;
}