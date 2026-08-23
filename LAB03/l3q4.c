#include <stdio.h>
#include <stdlib.h>
int next_power_of_two(int n){
    int size = 1;
    while (size < n)
        size *= 2;

    return size;
}
void add_matrix(int n,int A[n][n],int B[n][n],int C[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    }
}
void subtract_matrix(int n,int A[n][n],int B[n][n],int C[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    }
}
void strassen(int n,int A[n][n],int B[n][n],int C[n][n]){
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    int half = n / 2;
    int A11[half][half];
    int A12[half][half];
    int A21[half][half];
    int A22[half][half];

    int B11[half][half];
    int B12[half][half];
    int B21[half][half];
    int B22[half][half];

    int M1[half][half];
    int M2[half][half];
    int M3[half][half];
    int M4[half][half];
    int M5[half][half];
    int M6[half][half];
    int M7[half][half];

    int X[half][half];
    int Y[half][half];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }
    add_matrix(half, A11, A22, X);
    add_matrix(half, B11, B22, Y);
    strassen(half, X, Y, M1);

    add_matrix(half, A21, A22, X);
    strassen(half, X, B11, M2);

    subtract_matrix(half, B12, B22, Y);
    strassen(half, A11, Y, M3);

    subtract_matrix(half, B21, B11, Y);
    strassen(half, A22, Y, M4);

    add_matrix(half, A11, A12, X);
    strassen(half, X, B22, M5);

    subtract_matrix(half, A21, A11, X);
    add_matrix(half, B11, B12, Y);
    strassen(half, X, Y, M6);

    subtract_matrix(half, A12, A22, X);
    add_matrix(half, B21, B22, Y);
    strassen(half, X, Y, M7);
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] =
                M1[i][j] +
                M4[i][j] -
                M5[i][j] +
                M7[i][j];

            C[i][j + half] =
                M3[i][j] +
                M5[i][j];
            C[i + half][j] =
                M2[i][j] +
                M4[i][j];
            C[i + half][j + half] =
                M1[i][j] -
                M2[i][j] +
                M3[i][j] +
                M6[i][j];
        }
    }
}
void print_matrix(int n, int matrix[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}
int main(void){
    int n;
    printf("Enter the size of the matrices: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Matrix size must be positive.\n");
        return 1;
    }
    int size = next_power_of_two(n);
    int A[size][size];
    int B[size][size];
    int C[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;
        }
    }
    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);
    }
    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);
    }
    strassen(size, A, B, C);
    printf("Result matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }
    return 0;
