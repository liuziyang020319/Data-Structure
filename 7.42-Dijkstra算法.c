#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100010
struct Node{
    int u,v,w,nxt;
}e[N];
int cnt=0;
int first[N];
void add(int u,int v,int w){
    ++cnt;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=first[u];
    first[u]=cnt;
}
int n,S;
int dis[N];
int vis[N];
int Queue[N<<1];
int head=0,tail=-1;
void SPFA(int S){
    int i;
    for(i=1;i<=n;++i){
        dis[i]=1e9+7;
    }
    dis[S]=0;
    Queue[++tail]=S;
    dis[S]=0;
    vis[S]=1;
    while(head<=tail){
        int u=Queue[head++];
        vis[u]=0;
        for(i=first[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w){
                dis[v]=dis[u]+e[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    Queue[++tail]=v;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&S);
    int u,v,w;
    while(scanf("%d-%d%d",&u,&v,&w)!=EOF){
        add(u,v,w);
    }    
    int tot=0,i;
    SPFA(S);
    for(i=1;i<=n;++i){
        if(i!=S){
            printf("%d",dis[i]);
            ++tot;
            if(tot!=n-1)printf(",");
        }  
    }
    return 0;
}
