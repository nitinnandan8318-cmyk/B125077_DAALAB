#include <stdio.h>
#include <math.h>
#include <string.h>
double f1(double n){ return n*log2(n);}
double f2(double n){ return 12*(sqrt(n));}
double f3(double n){ return 1/n;}
double f4(double n){ return pow(n,(log2(n)));}
double f5(double n){ return 100*(pow(n,2))+6*n;}
double f6(double n){ return pow(n,0.51);}
double f7(double n){ return pow(n,2)-324;}
double f8(double n){ return 50*pow(n,0.5);}
double f9(double n){ return 2*pow(n,3);}
double f10(double n){ return pow(3,n);}
double f11(double n){ return pow(2,32)*n;}
double f12(double n){ return log2(n);}
void main(){
    char a[12][20]={ "n*log2(n)", "12*(sqrt(n))", "1/n", "n^(log2(n))", "100*(n^2)+6*n", "n^0.51", "(n^2)-324", "50*(n^0.5)", "2*n^3", "3^n", "(2*32)*n", "log2(n)" },temp[20];
    int smallest;
    double n=pow(10.0,8.0), lst[12]={
        log2(f1(n+1))-log2(f1(n)),
        log2(f2(n+1))-log2(f2(n)),
        log2(f3(n+1))-log2(f3(n)),
        log2(f4(n+1))-log2(f4(n)),
        log2(f5(n+1))-log2(f5(n)),
        log2(f6(n+1))-log2(f6(n)),
        log2(f7(n+1))-log2(f7(n)),
        log2(f8(n+1))-log2(f8(n)),
        log2(f9(n+1))-log2(f9(n)),
        log2(f10(n+1))-log2(f10(n)),
        log2(f11(n+1))-log2(f11(n)),
        log2(f12(n+1))-log2(f12(n))
    };
    for(int i=0;i<12;i++){
        smallest=i;
        for (int j=i;j<12;j++){
            if (lst[j]<lst[smallest]){
                smallest=j;
            }
        }
        lst[i]+=lst[smallest];
        lst[smallest]=lst[i]-lst[smallest];
        lst[i]-=lst[smallest];

        strcpy(temp, a[i]);
        strcpy(a[i], a[smallest]);
        strcpy(a[smallest],temp);
    }

    for (int i=0;i<12;i++)puts(a[i]);
}