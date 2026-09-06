#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int matrix_chain(int p[],int n){
    int m[n][n];
    for(int i=1;i<n;i++){
        m[i][i] = 0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i+l-1;
            m[i][j] =  INT_MAX;
            for(int k=i;k<j;k++){
                int cost = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }
    return m[1][n-1];
}
int main(){
    int n;
    printf("enter number of matrices : ");
    scanf("%d",&n);
    int *p = (int *)malloc((n+1) *sizeof(int));
    printf("\nenter dimensions \n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("minimum number of scalar multiplications : %d",matrix_chain(p,n));
    free(p);
    return 0;
}