#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr,int size){
    for(int i=0;i<size;i++) printf("%d ",*(arr+i));
    printf("\n");
}

int turn_off_all();

int turn_on_all(int *arr,int size){
    int counter=0;
    if (size<1) return 0;
    if (size==1){
        *(arr)=1;
        counter++;
    }
    counter+=turn_on_all(arr+1,size-1);
    *(arr)=1;
    counter++;
    counter+=turn_off_all(arr+1,size-1);
    return counter;
}
int turn_off_all(int *arr,int size){
    int counter=0;
    if (size<1) return 0;
    if(size==1){
        *(arr)=0;
        counter++;
    } else {
        counter+=turn_off_all(arr+2,size-2);
        *arr=0;
        counter++;
        counter+=turn_on_all(arr+2,size-2);
        counter+=turn_off_all(arr+1,size-1);
    }
    return counter;
}

int main(){
    int n,*arr,counter;
    printf("Enter the number of switches: ");
    scanf("%d",&n);
    
    arr=malloc(n*sizeof(int));
    for (int i=0;i<n;i++) *(arr+i)=1;

    printf("Original Array:\n");
    print_array(arr,n);

    counter=turn_off_all(arr,n);
    printf("Final Array:\n");
    print_array(arr,n);
    printf("Number of moves: %d\n",counter);

    free(arr);
    return 0;
}

//TIME COMPLEXITY
//print_array()       → O(n)
//turn_on_all()       → O(2.414^n)
//turn_off_all()      → O(2.414^n)
//main()              → O(2.414^n)