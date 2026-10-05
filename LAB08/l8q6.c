#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int editDistance(char A[],char B[]){
    int m = strlen(A);
    int n = strlen(B);
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i=0;i<=m;i++)
        dp[i] = (int *)malloc((n+1) * sizeof(int));
    for (int i=0;i<=m;i++)
        dp[i][0] = i;
    for(int j=0;j<=n;j++){
        dp[0][j] = j;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                int min = dp[i-1][j];
                if (dp[i][j-1] < min)
                    min = dp[i][j-1];
                if(dp[i-1][j-1] < min)
                    min = dp[i-1][j-1];
                dp[i][j] = 1 + min;
            }
        }
    }
    int i = m, j = n;
    printf("\nTraceback:\n");
    while (i > 0 || j > 0){
        if (i > 0 && j > 0 && A[i-1] == B[j-1]){
            printf("Keep '%c'\n", A[i - 1]);
            i--;
            j--;
        }else if (i > 0 && j > 0 && dp[i][j] == dp[i-1][j-1]+1){
            printf("Substitute '%c' with '%c'\n",A[i-1],B[j-1]);
            i--;
            j--;
        }else if (i > 0 && dp[i][j] == dp[i-1][j]+1){
            printf("Delete '%c'\n",A[i-1]);
            i--;
        }else{
            printf("Insert '%c'\n", B[j - 1]);
            j--;
        }
    }
    int ans = dp[m][n];
    for (int i=0;i<=m;i++)
        free(dp[i]);
    free(dp);
    return ans;
}
int main(){
    char A[100],B[100];
    printf("Enter first string: ");
    scanf("%s",A);
    printf("Enter second string: ");
    scanf("%s",B);
    printf("\nMinimum Edit Distance = %d\n",editDistance(A, B));
    return 0;
}