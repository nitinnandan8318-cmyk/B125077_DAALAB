#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lcs(char X[],char Y[],int m,int n){
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i=0;i<=m;i++)
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
    for(int i=0;i<=m;i++)
        dp[i][0] = 0;
    for(int j=0;j<=n;j++)
        dp[0][j] = 0;
    for(int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if(X[i-1] == Y[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else{
                if(dp[i-1][j] > dp[i][j-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
    }
    int length = dp[m][n];
    char *lcsString = (char *)malloc((length + 1) * sizeof(char));
    int i = m, j = n;
    int k = length - 1;
    while (i > 0 && j > 0){
        if (X[i-1] == Y[j-1]){
            lcsString[k] = X[i-1];
            k--;
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    lcsString[length] = '\0';
    printf("LCS Length = %d\n", length);
    printf("LCS = %s\n", lcsString);
    free(lcsString);
    for (int i = 0; i <= m; i++)
        free(dp[i]);
    free(dp);
    return length;
}
int main(){
    char X[100],Y[100];
    printf("Enter first sequence: ");
    scanf("%s",X);
    printf("Enter second sequence: ");
    scanf("%s",Y);
    lcs(X,Y,strlen(X),strlen(Y));
    return 0;
}