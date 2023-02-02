#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int G[1200][1200];
int n,tot;
void Del(int x){
    int i,j;
    for(i=x;i<tot;i++){
        for(j=0;j<=tot;j++){
            G[i][j]=G[i+1][j];
        }
    }
    for(j=x;j<tot;j++){
        for(i=0;i<tot;i++){
            G[i][j]=G[i][j+1];
        }
    }
    for(i=0;i<=tot;++i){
        G[i][tot]=G[tot][i]=0;
    }
    tot--;
}
void Add(int x){
    int i,j;
    tot++;
    for(i=tot;i>x;i--){
        for(j=0;j<=tot;++j){
            G[i][j]=G[i-1][j];
        }
    }
    for(j=tot;j>x;j--){
        for(i=0;i<=tot;++i){
            G[i][j]=G[i][j-1];
        }
    }
    for(i=0;i<=tot;++i){
        G[x][i]=G[i][x]=0;
    }
}
int main(){
    scanf("%d",&n);
    tot=n-1;
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            scanf("%d",&G[i][j]);
        }
    }
    char c=getchar();
    c=getchar();
    while(c!=EOF){
        if(c=='D'){
            c=getchar();
            if(c=='A'){
                int u,v;
                scanf("%d%d",&u,&v);
                G[u][v]=G[v][u]=0;
            }
            if(c=='V'){
                int x;
                scanf("%d",&x);
                Del(x);
            }
            c=getchar();
            if(c==EOF)break;
            c=getchar();
        }
        else 
            if(c=='I'){
                c=getchar();
                if(c=='A'){
                    int u,v;
                    scanf("%d%d",&u,&v);
                    G[u][v]=G[v][u]=1;
                }
                if(c=='V'){
                    int x;
                    scanf("%d",&x);
                    Add(x);
                }
                c=getchar();
                if(c==EOF)break;
                c=getchar();
            }
            else 
                c=getchar(); 
    }
    for(i=0;i<=tot;++i){
        for(j=0;j<=tot;++j){
            printf("%d",G[i][j]);
            if(j<tot)printf(" ");
        }
        if(i<tot)printf("\n");
    }
    return 0;
}