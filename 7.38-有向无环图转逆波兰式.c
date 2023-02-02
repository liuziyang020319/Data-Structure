#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100010
struct Node{
    int u,v,nxt;
}e[N];
int cnt=0;
int first[N];
void add(int u,int v){
    ++cnt;
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].nxt=first[u];
    first[u]=cnt;
}
int n;
char sum[N];
void DFS(int u){
    int i;
    for(i=first[u];i;i=e[i].nxt){
        int v=e[i].v;
        DFS(v);
    }
    printf("%c",sum[u]);
}
int main(){
    scanf("%d",&n);
    int i;
    char c=getchar();
    for(i=1;i<=n;++i){
        scanf("%c",&sum[i]);
        c=getchar();
        while(c!='\n'&&c!=EOF){
            int x=0;
            while(c<'0'||c>'9'){
                c=getchar();
            }
            while(c>='0'&&c<='9'){
                x=x*10+c-'0';
                c=getchar();
            }
            add(i,x+1);
        }
    }
    DFS(1);
    return 0;
}