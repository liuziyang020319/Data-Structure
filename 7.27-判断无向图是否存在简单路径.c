#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100010
struct Node{
    int u,v,nxt;
}e[N];
int first[N];
int vis[N];
int cnt=0;
int n,k;
void add(int u,int v){
    ++cnt;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].nxt=first[u];
    first[u]=cnt;
}
int flag=0;
int S,T;
void DFS(int u,int tot){
    if(tot==0){
        if(u==T)
            flag=1;
        return;
    }
    if(flag)
        return;
    int i;
    for(i=first[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(!vis[v]){
            vis[v]=1;
            DFS(v,tot-1);
            vis[v]=0;
        }
    }
}
int main(){
    scanf("%d,%d",&n,&k);
    scanf("%d,%d",&S,&T);
    char c=getchar();
    c=getchar();
	int cur=0;
	int u,v;
	while(c!='\n'&&c!=EOF){
		int x=0;
        while(c<'0'||c>'9'){
			c=getchar();
		}
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        if(cur==0){
            u=x;
        }
        else{
            v=x;
            add(u,v);
            add(v,u);
        }
        cur^=1;
	}    
    vis[S]=1;
    DFS(S,k);
    vis[S]=0;
    if(flag)
        printf("yes");
    else
        printf("no");
    return 0;
}