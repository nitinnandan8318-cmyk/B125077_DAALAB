#include <stdio.h>
#include <limits.h>
long long reve(int n){
    long long dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i<=n;i++) {
        dp[i] = LLONG_MAX;
        for (int k=1;k<i;k++) {
            long long threePeg = (1LL<<(i-k))-1;
            long long moves = 2*dp[k]+threePeg;
            if (moves < dp[i])
                dp[i] = moves;
        }
    }
    return dp[n];
}
int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("Minimum number of moves: %lld\n", reve(n));
    return 0;
}