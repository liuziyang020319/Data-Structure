#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CTNODE{
    int son;
    int sibling;
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
void DFS(int idx,int dep,NODEptr now){
    int i;
    for(i=1;i<=dep;++i)printf("-");
    printf("%c\n",now->data);
    do{
    	if(now->son!=-1)DFS(now->son,dep+1,Tree[now->son]);
        if(now->sibling!=-1){
	        now=Tree[now->sibling];
	        for(i=1;i<=dep;++i)printf("-");
	        printf("%c\n",now->data);  	
        }      
    }while(now->sibling!=-1);
}
int main(){
    while((scanf("%s %d %d",ch,&A,&B))!=EOF){
        Tree[++n]=GetNode();
        Tree[n]->son=A;
        Tree[n]->sibling=B; 
        Tree[n]->data=ch[0];
    }
    DFS(1,0,Tree[1]);
    return 0;
}
