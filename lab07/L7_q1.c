#include <stdio.h>
#include <stdlib.h>

int *input_triangle(int height){
    int column=2*height+1,*arr=malloc(height*column*sizeof(int));
    for (int i=0;i<height*column;i+=column){
        for (int j=0;j<column;j++) *(arr+i+j)=0;
        for (int j=(column-1)/2-(i+1)/column;j<=(column-1)/2+(i+1)/column;j+=2){
            *(arr+i+j)=1;
        }
    }
    return arr;
}
void print_triangle(int *arr,int height){
    int col=2*height+1;
    for (int i=0;i<height*col;i+=col){
        for (int j=0;j<col;j++) *(arr+i+j)==1?printf("%d ",0):printf("  ");
        printf("\n");
    }
}

int swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int unchanged_row(int *arr,int height){
    int column=2*height+1, a=0,b;
    for(int i=((height+1)/2)-1;i<height;i++){
        b=((height-i)*(3*(i+1)-height))/2;
        if(b>a) a=b;
        else return i;
    }
}
void shift_row_bottom(int *arr,int height,int row){
    int column=2*height+1,*temp=malloc(column*sizeof(int));

    for (int i=0;i<column;i++){
        *(temp+i)=*(arr+(row-1)*column+i);
    }
    for (int i=row;i<height;i++){
        for (int j=0;j<column;j++){
            *(arr+(i-1)*column+j)=*(arr+i*column+j);
        }
    }
    for (int i=0;i<column;i++){
        *(arr+(height-1)*column+i)=*(temp+i);
    }

    free(temp);
}
int invert_triangle(int *arr,int height){
    int column,a,b,counter=0,i;
    column=2*height+1;
    a=unchanged_row(arr,height);

    for (i=1;i<=height-a;i++){
        for (int j=0;j<i*2-1;j+=2){
            b=height-a-i+1;
            swap((arr+((a+i-1)*column)+b+j),(arr+((a-i-1)*column)+b+j));
            swap((arr+((a+i)*column)-b-j-1),(arr+((a-i)*column)-b-j-1));
            counter+=2;
        }
    }
    while(a-i-1>=0){
        shift_row_bottom(arr,height,a-i);
        counter+=a-i;
        i++;
    }

    return counter;
}

int main(){
    int h,counter;
    printf("Enter the height of the triangle: ");
    scanf("%d",&h);
    int *arr=input_triangle(h);

    printf("ORIGINAL TRIANGLE:\n");
    print_triangle(arr,h);

    counter=invert_triangle(arr,h);
    printf("INVERTED TRIANGLE:\n");
    print_triangle(arr,h);
    printf("Number of moves: %d\n",counter);

    free(arr);
    return 0;
}

//TIME COMPLEXITY
//input_triangle      O(h²)
//print_triangle      O(h²)
//invert_triangle     O(h²)
//main                O(h²)