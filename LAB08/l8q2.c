#include <stdio.h>
#include <stdlib.h>
int countWays(int coin[],int n,int V){
    int *dp = (int *)malloc((V + 1) * sizeof(int));
    for (int i = 0; i <= V; i++)
        dp[i] = 0;
    dp[0] = 1;
    for (int j = 0; j < n; j++){
        for (int i = coin[j]; i <= V; i++){
            dp[i] = dp[i] + dp[i - coin[j]];
        }
    }
    int ans = dp[V];
    free(dp);
    return ans;
}
int main(){
    int n,V;
    printf("Enter number of coins: ");
    scanf("%d",&n);
    int coin[n];
    printf("Enter coin denominations: ");
    for (int i = 0; i < n; i++){
        scanf("%d", &coin[i]);
    }
    printf("Enter target amount: ");
    scanf("%d",&V);
    printf("Total number of ways = %d\n",countWays(coin, n, V));
    return 0;
}