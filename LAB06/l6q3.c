#include <stdio.h>
#include <string.h>
int max(int a,int b) {
    return (a>b) ? a : b;
}
int lcs(char *A,char *B,int m,int n) {
    if(m==0 || n==0)
        return 0;
    if(A[m-1] == B[n-1])
        return 1 + lcs(A,B,m-1,n-1);
    return max(
        lcs(A,B,m-1,n),
        lcs(A,B,m,n-1)
    );
}
void printLCS(char *A,char *B,int m,int n){
    if(m==0 || n==0)
        return;
    if(A[m-1] == B[n-1]) {
        printLCS(A,B,m-1,n-1);
        printf("%c",A[m-1]);
    }else{
        int x = lcs(A,B,m-1,n);
        int y = lcs(A,B,m,n-1);
        if(x>y)
            printLCS(A,B,m-1,n);
        else
            printLCS(A,B,m,n-1);
    }
}
int main() {
    char A[100],B[100];
    printf("Enter first string: ");
    scanf("%s",A);
    printf("Enter second string: ");
    scanf("%s",B);
    int m = strlen(A);
    int n = strlen(B);
    int length = lcs(A,B,m,n);
    printf("Length of LCS = %d\n",length);
    printf("LCS = ");
    printLCS(A,B,m,n);
    printf("\n");
    return 0;
}