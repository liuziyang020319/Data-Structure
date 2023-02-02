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
int n;
NODEptr GetNode(){
    NODEptr ret = malloc(sizeof(CTNODE));
    memset(ret,0,sizeof(CTNODE));
    return ret;
}
int main(){
    while((scanf("%s %d %d",ch,&A,&B))!=EOF){
        Tree[++n]=GetNode();
        Tree[n]->lson=A;
        Tree[n]->rson=B; 
        Tree[n]->data=ch[0];
    }
    printf("%c",Tree[1]->data);
    Stack[++top]=Tree[1];
    while(!empty()){
        while(Stack[top]->lson!=-1&&!vis[Stack[top]->lson]){
            NODEptr now=Tree[Stack[top]->lson];
            printf(" %c",now->data);
            vis[Stack[top]->lson]=1;
            Stack[++top]=now;
        }
        if(Stack[top]->rson!=-1){
            NODEptr now=Tree[Stack[top]->rson];
            printf(" %c",now->data);
            Stack[top]=now;            
        }
        else{top--;}
    }
    return 0;
}
