#include <stdio.h>
#include <stdlib.h>
void reverse(int p[],int i,int j){
    while(i<j){
        int temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}
void printArray(int p[],int n){
    for (int i=0;i<n;i++)
        printf("%d\t",p[i]);
    printf("\n");
}
int findPosition(int p[],int n,int value){
    for (int i=0;i<n;i++){
        if(p[i]==value)
            return i;
    }
    return -1;
}
void sortByReversal(int p[],int n){
    for (int value=1;value<=n;value++){
        int pos = findPosition(p,n,value);
        if (pos != value-1){
            reverse(p,value-1,pos);
            printf("After reverse: ");
            printArray(p,n);
        }
    }
}
int main(){
    int n;
    printf("Enter size of permutation: ");
    scanf("%d",&n);
    int *p = malloc(n *sizeof(int));
    printf("Enter permutation:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("\nOriginal permutation: ");
    printArray(p,n);
    sortByReversal(p,n);
    printf("\nSorted permutation: ");
    printArray(p,n);
    free(p);
    return 0;
}