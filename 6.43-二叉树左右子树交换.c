#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CTNODE{
    struct CTNODE * lson;
    struct CTNODE * rson;
}* NODEptr;
NODEptr Tree[1000+10];
int L[1000+10],lcnt=-1;
int R[1000+10],rcnt=-1;
char c;
int main(){
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        L[++lcnt]=0;
        while(c>='0'&&c<='9'){
            L[lcnt]=L[lcnt]*10+c-'0';
            c=getchar();
        }
        if(c=='\n')break;
    }
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        R[++rcnt]=0;
        while(c>='0'&&c<='9'){
            R[rcnt]=R[rcnt]*10+c-'0';
            c=getchar();
        }
        if(c==EOF||c=='\n')break;
    }
    int i;
    for(i=0;i<rcnt;++i)printf("%d ",R[i]);
    printf("%d\n",R[i]);
    for(i=0;i<lcnt;++i)printf("%d ",L[i]);
    printf("%d",L[i]);
    return 0;
}
