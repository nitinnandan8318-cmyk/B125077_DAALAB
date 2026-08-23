#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int x;
    char ch[30];
}rahul;
int swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int n,redcount=0,bluecount=0,yellowcount=0;
    printf("enter number of elements:");
    scanf("%d",&n);
    rahul r[n];
    printf("\nenter elements\n");
    for(int i=0;i<n;i++){
        printf("enter number : ");
        scanf("%d",&r[i].x);
        printf("enter colour(red , blue or yellow)");
        scanf("%s",r[i].ch);
    }
    for(int i=0;i<n;i++){
        if(strcmp(r[i].ch,"red")==0)
            redcount++;
        else if(strcmp(r[i].ch,"blue")==0)
            bluecount++;
        else
            yellowcount++;
    }
    rahul *redarr = (rahul *)malloc(redcount *sizeof(rahul));
    rahul *bluearr = (rahul *)malloc(bluecount *sizeof(rahul));
    rahul *yellowarr = (rahul *)malloc(yellowcount *sizeof(rahul));
    redcount=0,bluecount=0,yellowcount=0;
    for(int i=0;i<n;i++){
        if(strcmp(r[i].ch,"red")==0){
            strcpy(redarr[redcount].ch,r[i].ch);
            redarr[redcount].x=r[i].x;
            redcount++;
        }else if(strcmp(r[i].ch,"blue")==0){
            strcpy(bluearr[bluecount].ch,r[i].ch);
            bluearr[bluecount].x=r[i].x;
            bluecount++;
        }else{
            strcpy(yellowarr[yellowcount].ch,r[i].ch);
            yellowarr[yellowcount].x=r[i].x;
            yellowcount++;
        }
    }
    int k=0;
    for(int i=0;i<redcount;i++){
        r[k++]=redarr[i];
    }
    for(int i=0;i<bluecount;i++){
        r[k++]=bluearr[i];
    }
    for(int i=0;i<yellowcount;i++){
        r[k++]=yellowarr[i];
    }
    free(redarr);
    free(bluearr);
    free(yellowarr);
    for(int i=0;i<n;i++){
        printf("number : %d\nnumber colour : %s\n",r[i].x,r[i].ch);
    }
    return 0;
}
