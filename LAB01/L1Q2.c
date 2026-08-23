#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int n, i;
    int fairhead = 0, biasedhead = 0;
    printf("Enter number of tosses: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(i=0;i<n;i++){
        if(rand()%2==0){
            fairhead++;
        }
    }
    for(i=0;i<n;i++){
        if((rand()%10)<7){
            biasedhead++;
        }
    }
    printf("\nFair Coin\n");
    printf("Heads = %d\n",fairhead);
    printf("Tails = %d\n",n-fairhead);
    printf("P(Head) = %.4f\n",(float)fairhead/n);
    printf("\nBiased Coin\n");
    printf("Heads = %d\n",biasedhead);
    printf("Tails = %d\n",n-biasedhead);
    printf("P(Head) = %.4f\n",(float)biasedhead/n);
    return 0;
}