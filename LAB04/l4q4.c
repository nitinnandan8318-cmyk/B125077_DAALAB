#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
int main(){
    int n;
    printf("enter number of entry and exit :");
    scanf("%d",&n);
    int *entry = (int *)malloc(n *sizeof(int));
    int *exit = (int *)malloc(n *sizeof(int));
    printf("\nenter first set elements\n");
    for(int i=0;i<n;i++){
        printf("enter entry time : ");
        scanf("%d",&entry[i]);
        printf("enter exit time : ");
        scanf("%d",&exit[i]);
        printf("\n");
    }
    qsort(entry, n, sizeof(int), compare);
    qsort(exit, n, sizeof(int), compare);
    int i=0,j=0,current=0,max=0,maxtime=0;
    while (i<n && j<n){
        if(entry[i] < exit[j]){
            current++;
            if(current > max){
                max = current;
                maxtime = entry[i];
            }
            i++;
        }else{
            current--;
            j++;
        }
    }
    printf("\nmaximum people present : %d\ntime : %d\n",max,maxtime);
    free(entry);
    free(exit);
    return 0;
}
