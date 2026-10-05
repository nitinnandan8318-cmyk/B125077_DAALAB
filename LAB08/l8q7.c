#include <stdio.h>
#include <stdlib.h>
int rodCutting(int price[],int n,int cut[]){
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        dp[i] = 0;
        for (int j=1;j<=i;j++){
            if(price[j]+dp[i-j] > dp[i]){
                dp[i] = price[j] + dp[i-j];
                cut[i] = j;
            }
        }
    }
    int maxRevenue = dp[n];
    free(dp);
    return maxRevenue;
}
void printCuts(int cut[],int n){
    printf("Pieces: ");
    while (n > 0){
        printf("%d ",cut[n]);
        n = n - cut[n];
    }
    printf("\n");
}
int main(){
    int n;
    printf("Enter rod length: ");
    scanf("%d",&n);
    int *price = (int *)malloc((n + 1) * sizeof(int));
    int *cut = (int *)malloc((n + 1) * sizeof(int));
    price[0] = 0;
    printf("Enter prices for lengths 1 to %d:\n",n);
    for (int i=1;i<=n;i++){
        scanf("%d", &price[i]);
    }
    printf("Maximum Revenue = %d\n",rodCutting(price,n,cut));
    printCuts(cut, n);
    free(price);
    free(cut);
    return 0;
}