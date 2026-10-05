#include <stdio.h>
#include <stdlib.h>

int shoot(int *arr,int size,int shoot_pos){
    printf("Shot at position %d.\n",shoot_pos+1);
    if(*(arr+shoot_pos)==1){
        printf("Target shot at position %d\n",shoot_pos+1);
        return 1;
    }
    return 0;
}
void game_simulation(int *arr,int size,int player_pos){
    int option,check,shoot_pos=0;
    *(arr+player_pos)=1;

    while(shoot_pos<size){
        check=shoot(arr,size,shoot_pos++);
        if(check) return;
        check=shoot(arr,size,shoot_pos);
        if(check) return;

        printf("Press -1 to move left, 1 to move right: ");
        scanf("%d",&option);

        if((player_pos==0 && option==-1) || (player_pos==size-1 && option==1)){
            printf("Invalid position. Player not moved.\n");
        } else if(option==1 || option==-1){
            *(arr+player_pos)=0;
            player_pos+=option;
            *(arr+player_pos)=1;
            printf("Player moved to position %d.\n",player_pos+1);
        }else{
            printf("Invalid input. Player not moved.");
        }
    }
    
    printf("Target not found.\n");
    return;
}

int main(){
    int n,*arr,pos;
    printf("Enter the number of hiding spots: ");
    scanf("%d",&n);

    arr=malloc(n*sizeof(int));
    for (int i=0;i<n;i++) *(arr+i)=0;
    
    printf("Enter player starting position: ");
    scanf("%d",&pos);

    game_simulation(arr,n,pos-1);

    free(arr);
    return 0;
}

//TIME COMPLEXITY
//shoot()              O(1)
//game_simulation()    O(n)