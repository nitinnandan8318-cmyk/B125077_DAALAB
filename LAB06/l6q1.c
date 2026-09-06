#include<stdio.h>
int main(){
    int n;
    printf("enter number of terms : ");
    scanf("%d",&n);
    int a=1,b=1,c=0;
    for(int i=1;i<=n;i++){
        if(i<=2)
            printf("1\t");
        else{
            c=a+b;
            b=a;
            a=c;
            printf("%d\t",c);
        }
    }
    return 0;
}