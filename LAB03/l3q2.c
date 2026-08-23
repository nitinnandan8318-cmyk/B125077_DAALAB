#include <stdio.h>
#include <stdlib.h>
int weigh(const double coins[],int left1, int right1,int left2, int right2){
    double left_sum = 0.0;
    double right_sum = 0.0;
    for (int i = left1; i <= right1; i++)
        left_sum += coins[i];
    for (int i = left2; i <= right2; i++)
        right_sum += coins[i];
    if (left_sum < right_sum)
        return -1;
    if (left_sum > right_sum)
        return 1;
    return 0;}
int find_reference_coin(const double coins[], int n){
    int group_size = n / 2;
    if (group_size == 0)
        return -1;
    int result = weigh(coins,0,group_size - 1,group_size,2 * group_size - 1);
    if (result == -1)
        return group_size;
    return 0;}
int find_defective_coin(const double coins[],int left,int right,int reference){
    while (left <= right) {
        int count = right - left + 1;
        if (count == 1) {
            if (coins[left] < coins[reference])
                return left;
            return -1;
        }
        int half = count / 2;
        int left_group_start = left;
        int left_group_end = left + half - 1;
        int right_group_start;
        int right_group_end = right;
        if (count % 2 == 0) right_group_start = left + half;
        else right_group_start = left + half + 1;
        int result = weigh(coins,left_group_start,left_group_end,right_group_start,right_group_end);
        if (result == -1) {
            left = left_group_start;
            right = left_group_end;
        } else if (result == 1) {
            left = right_group_start;
            right = right_group_end;
        } else {
            if (count % 2 == 1) {
                int middle = left + half;
                if (coins[middle] < coins[reference])
                    return middle;
            }
            return -1;
        }
    }
    return -1;
}
int main(void){
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("At least two coins are required.\n");
        return 1;
    }
    double *coins = malloc(n * sizeof(double));
    if (coins == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter the weights of the coins:\n");
    for (int i = 0; i < n; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%lf", &coins[i]);
    }
    int reference = find_reference_coin(coins, n);
    if (reference == -1) {
        printf("Could not obtain a reference coin.\n");
        free(coins);
        return 1;
    }
    int defective = find_defective_coin(coins,0,n - 1,reference);
    if (defective == -1) printf("No defective coin was found.\n");
    else printf("Coin %d is defective and lighter.\n", defective + 1);
    free(coins);
    return 0;
}