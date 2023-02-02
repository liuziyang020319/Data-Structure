#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum TYPE {Link,Thread};
typedef struct CTNODE{
    struct CTNODE * lson;
    struct CTNODE * rson;
    struct CTNODE * fa;
    char data;
}* NODEptr,CTNODE;
NODEptr GetNode(){
    NODEptr ret = malloc(sizeof(CTNODE));
    memset(ret,0,sizeof(CTNODE));
    return ret;
}
char s[1000+10];
int pos,len;
char u[1],v[1];
NODEptr Nu,Nv;
int depu,depv;
NODEptr DFS(NODEptr fa,char now,int dep){
    if(pos>=len)return;
    NODEptr ret=GetNode();
    ret->data=now;
    ret->fa=fa;
    if(now==u[0])Nu=ret,depu=dep;
    if(now==v[0])Nv=ret,depv=dep;
    if(s[pos+1]!='^'){
        pos++;
        ret->lson=DFS(ret,s[pos],dep+1);
    }
    else pos++;
    if(s[pos+1]!='^'){
        pos++;
        ret->rson=DFS(ret,s[pos],dep+1);
    }
    else pos++;
    return ret;
}
int main(){
    scanf("%s%s%s",s,u,v);
    len=strlen(s);
    NODEptr RT=DFS(NULL,s[0],1);
	if(depu<depv){
        int i;
        for(i=depu+1;i<=depv;++i){
            Nv=Nv->fa;
        }
    }
    if(depu>depv){
        int i;
        for(i=depv+1;i<=depu;++i){
            Nu=Nu->fa;
        }
    }
    if(Nu==Nv&&Nu!=RT){
    	printf("%c",Nu->fa->data);
    	return 0;
    }
    while(Nu!=Nv){
        Nu=Nu->fa;
        Nv=Nv->fa;
    }
    printf("%c",Nu->data);
    return 0;
}
