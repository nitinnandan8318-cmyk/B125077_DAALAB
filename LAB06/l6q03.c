#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double real;
    double imag;
} Complex;
Complex multiply(Complex a, Complex b){
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}
void fft(Complex *a, int n, int invert){
    if (n == 1)
        return;
    Complex *even = malloc((n/2) *sizeof(Complex));
    Complex *odd = malloc((n/2) *sizeof(Complex));
    for (int i=0;i<n/2;i++){
        even[i] = a[2*i];
        odd[i] = a[2*i+1];
    }
    fft(even,n/2,invert);
    fft(odd,n/2,invert);
    double angle = 2*acos(-1.0)/n;
    if (invert)
        angle = -angle;
    Complex w;
    w.real = 1;
    w.imag = 0;
    Complex wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);
    for (int i=0;i<n/2;i++){
        Complex t = multiply(w, odd[i]);
        a[i].real = even[i].real + t.real;
        a[i].imag = even[i].imag + t.imag;
        a[i+n/2].real = even[i].real - t.real;
        a[i+n/2].imag = even[i].imag - t.imag;
        w = multiply(w, wn);
    }

    free(even);
    free(odd);
}
void convolution(int *A, int m, int *B, int n){
    int size = 1;
    while (size < m+n-1)
        size *= 2;
    Complex *a = calloc(size, sizeof(Complex));
    Complex *b = calloc(size, sizeof(Complex));
    for (int i = 0; i < m; i++)
        a[i].real = A[i];
    for (int i = 0; i < n; i++)
        b[i].real = B[i];
    fft(a, size, 0);
    fft(b, size, 0);
    for (int i=0;i<size;i++)
        a[i] = multiply(a[i],b[i]);
    fft(a,size,1);
    printf("\nConvolution:\n");
    for (int i=0;i<m+n-1;i++){
        printf("%d\t",(int)round(a[i].real/size));
    }
    printf("\n");
    free(a);
    free(b);
}
int main(){
    int m,n;
    printf("Enter size of vector A: ");
    scanf("%d",&m);
    printf("Enter size of vector B: ");
    scanf("%d",&n);
    if (n<m){
        printf("Condition n >= m is required.\n");
        return 0;
    }
    int *A = malloc(m *sizeof(int));
    int *B = malloc(n *sizeof(int));
    printf("Enter elements of A:\n");
    for (int i=0;i<m;i++){
        scanf("%d", &A[i]);
    }
    printf("Enter elements of B:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &B[i]);
    }
    convolution(A, m, B, n);
    free(A);
    free(B);
    return 0;
}