#include<stdio.h>
#include<math.h>
void add(int n,int arr[n][n],int brr[n][n],int crr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            crr[i][j] = arr[i][j] + brr[i][j];
        }
    }
}
void sub(int n,int arr[n][n],int brr[n][n],int crr[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            crr[i][j] = arr[i][j] - brr[i][j];
        }
    }
}
void multi(int n,int arr[n][n],int brr[n][n],int crr[n][n]){
    if(n==1){
        crr[0][0] = arr[0][0] * brr[0][0];
        return;
    }
    int k = n/2;
    int a1[k][k],a2[k][k],b1[k][k],b2[k][k];
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            a1[i][j]=arr[i][j];
            a2[i][j]=arr[i][j+k];
            b1[i][j]=brr[i][j];
            b2[i][j]=brr[i][j+k];
        }
    }
    int x[k][k],y[k][k], p[k][k],q[k][k];
    add(k,a1,a2,x);
    add(k,b1,b2,y);
    multi(k,x,y,p);
    sub(k,a1,a2,x);
    sub(k,b1,b2,y);
    multi(k,x,y,q);
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            crr[i][j] = (p[i][j] + q[i][j])/2;
            crr[i][j+k] = (p[i][j] - q[i][j])/2;
            crr[i+k][j] = (p[i][j] + q[i][j])/2;
            crr[i+k][j+k] = (p[i][j] - q[i][j])/2;
        }
    }
}