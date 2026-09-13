#include<stdio.h>
int super_egg(int e,int f){
    int count=0,m=e-1;
    while (f>=0){
        f -= m;
        m += e-1;
        count++;
    }
    return count;
}
int main(){
    int e,f;
    printf("enter number of eggs : ");
    scanf("%d",&e);
    printf("enter number of floor : ");
    scanf("%d",&f);
    printf("minimum number of droping : %d\n",super_egg(e,f));
    return 0;
}