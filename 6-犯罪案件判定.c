#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N (200000+10)
int fa[N],n,m,cnt;
char opt[1];
int front[N];
int Tar[N];
int Nxt[N];
void add(int u,int v){
    ++cnt;
    Tar[cnt]=v;
    Nxt[cnt]=front[u];
    front[u]=cnt;
}
void init(){
    int i;
    for(i=1;i<=n;++i)fa[i]=i;
    for(i=1;i<=n;++i)front[i]=0;
    for(i=1;i<=cnt;++i)Nxt[i]=0,Tar[i]=0;
    cnt=0;
}
int Getfa(int x){
    if(fa[x]==x)return x;
    else return fa[x]=Getfa(fa[x]);
}
void Union(int x,int y){
    int dx=Getfa(x);
    int dy=Getfa(y);
    fa[dy]=dx;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        init();
        int Cas;
        for(Cas=1;Cas<=m;++Cas){
            int u,v;
            scanf("%s %d %d",opt,&u,&v);
            if(opt[0]=='A'){
                int du=Getfa(u);
                int dv=Getfa(v);
                if(front[u]==0||front[v]==0){
                    printf("不确定\n");
                }
                else{
                    if(du==dv){
                        printf("是同一个团伙所为\n");
                    }
                    else{
                        int df=Getfa(Tar[front[u]]);
                        if(df==dv)
                            printf("不是同一个团伙所为\n");
                        else 
                            printf("不确定\n");
                    }
                }
            }
            else{
                if(front[u])Union(Tar[front[u]],v);
                if(front[v])Union(Tar[front[v]],u);
                add(u,v);
                add(v,u);
            }            
        }
    }
    return 0;
}
