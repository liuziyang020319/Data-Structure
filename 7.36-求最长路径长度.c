#include<stdio.h>
#include<string.h>
#define N 100010
struct Front_Star{
    int u,v,nxt;
}E[N];
int cnt=0;
int first[N];
int Rd[N];
int Dp[N];
void add(int u,int v){
    ++cnt;
    E[cnt].u=u;
    E[cnt].v=v;
    Rd[v]++;
    E[cnt].nxt=first[u];
    first[u]=cnt;
}
void Clr(){
    memset(first,0,sizeof(first));
    int i;
    for(i=0;i<N;++i){
        E[i].u=E[i].v=E[i].nxt=0;
    }
    cnt=0;
}
int n;
int Queue[N*2];
int head=0,tail=-1;
int main(){
	Clr(); 
    scanf("%d",&n);
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
            add(v,u);
        }
        cur^=1;
	}
    int i;
    for(i=1;i<=n;++i){
        if(!Rd[i])Queue[++tail]=i;
    }
    while(head<=tail){
        int u=Queue[head++];
        int i;
        for(i=first[u];i;i=E[i].nxt){
            int v=E[i].v;
            Dp[v]=(Dp[u]+1>Dp[v])?Dp[u]+1:Dp[v];
            Rd[v]--;
            if(Rd[v]==0){
                Queue[++tail]=v;
            }
        }
    }
    if(n==1){
        printf("0");
        return 0;
    }
    for(i=1;i<n;++i){
        printf("%d,",Dp[i]);
    }
    printf("%d",Dp[n]);
    return 0;
}
