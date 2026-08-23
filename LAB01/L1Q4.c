#include<stdio.h>
int moves=0;
void toh(int n,char s,char a,char d){
    if(n==1){
        printf("Move disk 1 from %c to %c\n", s, d);
        moves++;
        return;
    }
    toh(n-1,s,d,a);
    printf("Move disk %d from %c to %c\n",n,s,d);
    moves++;
    toh(n - 1,a,s,d);
}
int main(){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    toh(n,'A','B','C');
    printf("\nTotal Moves = %d\n",moves);
    return 0;
}