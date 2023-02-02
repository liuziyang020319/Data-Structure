#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CTNODE{
    int lson;
    int rson;
    char data;
}* NODEptr,CTNODE;
NODEptr Tree[1000+10];
NODEptr Stack[1000+10];
int top=0;
int vis[1000+10];
int empty(){
    return top==0;
}
char ch[1];
int A,B,vis[1000+10];
int n,GG;
NODEptr GetNode(){
    NODEptr ret = malloc(sizeof(CTNODE));
    memset(ret,0,sizeof(CTNODE));
    return ret;
}
void DFS(int idx,NODEptr now){
    if(now->lson!=-1){
        if(now->lson!=2*idx){
            GG=1;
            return;
        }
        DFS(now->lson,Tree[now->lson]);
    }
    if(now->rson!=-1){
        if(now->rson!=2*idx+1){
            GG=1;
            return;
        }
        DFS(now->rson,Tree[now->rson]);
    }
}
int main(){
    while((scanf("%s %d %d",ch,&A,&B))!=EOF){
        Tree[++n]=GetNode();
        Tree[n]->lson=A;
        Tree[n]->rson=B; 
        Tree[n]->data=ch[0];
    }
    DFS(1,Tree[1]);
    if(GG)printf("No");
    else printf("Yes");
    return 0;
}
