#include<stdio.h>
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
int main(){
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    if(x<y)swap(&x,&y);
    if(y<z)swap(&y,&z);
    if(x<y)swap(&x,&y);
    printf("%d %d %d",x,y,z);
    return 0;
}
