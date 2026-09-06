#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void addition(int n, int arr[][n], int brr[][n]){
    int crr[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            crr[i][j] = arr[i][j] + brr[i][j];
        }
    }
    printf("\nMatrix Addition:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", crr[i][j]);
        }
        printf("\n");
    }
}
void multiplication(int n, int arr[][n], int brr[][n]){
    int crr[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            crr[i][j] = 0;
            for (int k = 0; k < n; k++){
                crr[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }
    printf("\nMatrix Multiplication:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", crr[i][j]);
        }
        printf("\n");
    }
}
int zeromatrix(int n, int arr[][n]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (arr[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
int symmetricmatrix(int n, int arr[][n]){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i][j] != arr[j][i]){
                return 0;
            }
        }
    }
    return 1;
}
int determinant(int **arr, int n){
    if (n == 1)
        return arr[0][0];
    if (n == 2){
        return arr[0][0] * arr[1][1]
             - arr[0][1] * arr[1][0];
    }
    int det = 0;
    int **subarr = malloc((n - 1) * sizeof(int *));
    for (int i = 0; i < n - 1; i++){
        subarr[i] = malloc((n - 1) * sizeof(int));
    }
    for (int col = 0; col < n; col++){
        int subi = 0;
        for (int i = 1; i < n; i++){
            int subj = 0;
            for (int j = 0; j < n; j++){
                if (j == col)
                    continue;
                subarr[subi][subj] = arr[i][j];
                subj++;
            }
            subi++;
        }
        int sign;
        if (col % 2 == 0)
            sign = 1;
        else
            sign = -1;
        det += sign * arr[0][col] * determinant(subarr, n - 1);
    }
    for (int i = 0; i < n - 1; i++){
        free(subarr[i]);
    }
    free(subarr);
    return det;
}
void transposing(int n, int arr[][n]){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    printf("\nTranspose:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void eigenvalue_eigenvector(double a, double b, double c, double d){
    double trace = a + d;
    double determinant = a * d - b * c;
    double discriminant =trace * trace - 4 * determinant;
    if (discriminant < 0){
        printf("\nComplex eigenvalues.\n");
        return;
    }
    double lambda1 =(trace + sqrt(discriminant)) / 2;
    double lambda2 =(trace - sqrt(discriminant)) / 2;
    printf("\nEigenvalue 1 = %.2lf\n", lambda1);
    printf("Eigenvalue 2 = %.2lf\n", lambda2);
    if (b != 0){
        printf("Eigenvector 1 = [%.2lf, %.2lf]\n",b, lambda1 - a);
        printf("Eigenvector 2 = [%.2lf, %.2lf]\n",b, lambda2 - a);
    }
    else if (c != 0){
        printf("Eigenvector 1 = [%.2lf, %.2lf]\n",lambda1 - d, c);
        printf("Eigenvector 2 = [%.2lf, %.2lf]\n",lambda2 - d, c);
    }
    else{
        printf("Eigenvector 1 = [1.00, 0.00]\n");
        printf("Eigenvector 2 = [0.00, 1.00]\n");
    }
}
int main(){
    int n;
    printf("Enter the size of matrix: ");
    scanf("%d", &n);
    int arr[n][n];
    int brr[n][n];
    printf("\nEnter elements of first matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nEnter elements of second matrix:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &brr[i][j]);
        }
    }
    addition(n, arr, brr);
    multiplication(n, arr, brr);
    if (zeromatrix(n, arr))
        printf("\nFirst matrix is a zero matrix.\n");
    else
        printf("\nFirst matrix is not a zero matrix.\n");
    if (symmetricmatrix(n, arr))
        printf("First matrix is symmetric.\n");
    else
        printf("First matrix is not symmetric.\n");
    int **darr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++){
        darr[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++){
            darr[i][j] = arr[i][j];
        }
    }
    printf("\nDeterminant = %d\n",determinant(darr, n));
    for (int i = 0; i < n; i++){
        free(darr[i]);
    }
    free(darr);
    if (n == 2)
        eigenvalue_eigenvector(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
    else
        printf("\nEigenvalue/eigenvector is implemented for 2x2 matrix only.\n");
    tansposing(n, arr);
    return 0;
}