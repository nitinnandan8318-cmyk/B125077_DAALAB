#include <stdio.h>
#include <stdlib.h>
int maxSumIS(int A[],int n){
    int *dp = (int *)malloc(n * sizeof(int));
    for (int i=0;i<n;i++)
        dp[i] = A[i];
    for (int i=1;i<n;i++){
        for (int j=0;j<i;j++){
            if (A[j] < A[i] && dp[j]+A[i] > dp[i])
                dp[i] = dp[j] + A[i];
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
        scanf("%d", &A[i]);
    }
    printf("Maximum Sum Increasing Subsequence = %d\n",maxSumIS(A,n));
    return 0;
}
