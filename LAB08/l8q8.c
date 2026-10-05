#include <stdio.h>
#include <stdlib.h>
double optimalBST(double p[],double q[],int n){
    double **e = (double **)malloc((n + 2) * sizeof(double *));
    double **w = (double **)malloc((n + 2) * sizeof(double *));
    int **root = (int **)malloc((n + 2) * sizeof(int *));
    for (int i=0;i<=n+1;i++){
        e[i] = (double *)malloc((n + 1) * sizeof(double));
        w[i] = (double *)malloc((n + 1) * sizeof(double));
        root[i] = (int *)malloc((n + 1) * sizeof(int));
    }
    for (int i=1;i<=n+1;i++){
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    for (int length=1;length<=n;length++){
        for (int i=1;i<=n-length+1;i++){
            int j = i+length-1;
            e[i][j] = 999999;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for (int r=i;r<=j;r++){
                double cost = e[i][r-1] + e[r+1][j] + w[i][j];
                if (cost < e[i][j]){
                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }
    printf("\nMinimum Expected Search Cost = %.2lf\n", e[1][n]);
    printf("Root of optimal tree = k%d\n", root[1][n]);
    double ans = e[1][n];
    for (int i=0;i<=n+1;i++){
        free(e[i]);
        free(w[i]);
        free(root[i]);
    }
    free(e);
    free(w);
    free(root);
    return ans;
}
int main(){
    int n;
    printf("Enter number of keys: ");
    scanf("%d",&n);
    double *p = (double *)malloc((n + 1) * sizeof(double));
    double *q = (double *)malloc((n + 1) * sizeof(double));
    printf("Enter successful search probabilities:\n");
    for (int i=1;i<=n;i++)
        scanf("%lf", &p[i]);
    printf("Enter dummy search probabilities:\n");
    for (int i=0;i<=n;i++)
        scanf("%lf", &q[i]);
    optimalBST(p,q,n);
    free(p);
    free(q);
    return 0;
}