#include <stdio.h>
#include <stdlib.h>
int LIS(int A[],int n){
    int *dp = (int *)malloc(n * sizeof(int));
    for (int i=0;i<n;i++)
        dp[i] = 1;
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (A[j] < A[i] && dp[j]+1 > dp[i])
                dp[i] = dp[j] + 1;
        }
    }
    int max = dp[0];
    for (int i=1;i<n;i++){
        if (dp[i] > max)
            max = dp[i];
    }
    free(dp);
    return max;
}
int main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter elements: ");
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    printf("Length of LIS = %d\n",LIS(A, n));
    return 0;
}