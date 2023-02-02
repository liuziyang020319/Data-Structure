#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int u,v,nxt;
}E[100010];
int cnt=0;
int first[100010];
int Rd[100010];
int vis[100010];
void add(int u,int v){
    cnt++;
    E[cnt].u=u;
    E[cnt].v=v;
    Rd[v]++;
    E[cnt].nxt=first[u];
    first[u]=cnt;
}
int s[100010];
int fst[100010];
int lst[100010];
int n;
int Queue[100010];
int head=0;
int tail=-1;
int main(){
    scanf("%d",&n);
    int i;
	char c=getchar();
    c=getchar();
	while(c!='\n'){
		int x=0;
        while(c<'0'||c>'9'){
			c=getchar();
		}
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        s[i++]=x;
	}
    for(i=0;i<=n;++i){
        scanf("%d",&fst[i]);
    }
    for(i=0;i<=n;++i){
        scanf("%d",&lst[i]);
    }
    for(i=1;i<=n;++i){
        int j;
        for(j=fst[i];j<lst[i];++j){
            add(i,s[j]);
        }
    }
    for(i=1;i<=n;++i){
        if(Rd[i]==0)Queue[++tail]=i;
    }
    while(head<=tail){
        int u=Queue[head++];
        vis[u]=1;
        for(i=first[u];i;i=E[i].nxt){
            int v=E[i].v;
            Rd[v]--;
            if(!Rd[v])Queue[++tail]=v;
        }
    }
    int flag=0;
    for(i=1;i<=n;++i){
        if(!vis[i])flag=1;
    }
    if(flag)
        printf("yes");
    else 
        printf("no");
    return 0;
}