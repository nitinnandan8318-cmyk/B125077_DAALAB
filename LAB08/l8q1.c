#include <stdio.h>
#include <stdlib.h>
#define INF 999999
int minCoins(int coin[],int n,int V){
    int *dp = (int *)malloc((V + 1) * sizeof(int));
    dp[0] = 0;
    for(int i=1;i<=V;i++)
        dp[i] = INF;
    for(int i=1;i<=V;i++){
        for(int j=0;j<n;j++){
            if (coin[j] <= i && dp[i - coin[j]] != INF){
                if (dp[i-coin[j]]+1 < dp[i])
                    dp[i] = dp[i-coin[j]] + 1;
            }
        }
    }
    int ans = dp[V];
    free(dp);
    if(ans == INF)
        return -1;
    return ans;
}
int main(){
    int n,V;
    printf("Enter number of coins: ");
    scanf("%d",&n);
    int coin[n];
    printf("Enter coin denominations: ");
    for (int i=0;i<n;i++){
        scanf("%d", &coin[i]);
    }
    printf("Enter target amount: ");
    scanf("%d",&V);
    printf("Minimum number of coins = %d\n",minCoins(coin, n, V));
    return 0;
}