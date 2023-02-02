#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct G_List{
    int v,info;
    struct G_List *nxt;
}*GL;
struct G{
    GL first;
}E[100000+10];
int n,m;
int Zero;
void Init(){
    int i;
    for(i=0;i<=n+10;++i){
        E[i].first=malloc(sizeof(struct G_List));
        memset(E[i].first,0,sizeof(struct G_List));
        E[i].first->nxt=NULL;
    }
}
void add(int u,int v){
    GL pre=E[u].first;
    for(;pre->nxt!=NULL&&pre->nxt->v>v;pre=pre->nxt);
    GL now = malloc(sizeof(struct G_List));
    memset(now,0,sizeof(struct G_List));
    now->v=v;
    now->nxt=pre->nxt;
    pre->nxt=now;
}
int main(){
    scanf("%d,%d",&n,&m);
    Init();
    int i,u,v;
    scanf("%d-%d",&u,&v);
    if(u==0||v==0)Zero=1;
    add(u,v);
    for(i=2;i<=m;++i){
        scanf(",%d-%d",&u,&v);	  
        if(u==0||v==0)Zero=1;    
        add(u,v);  
    }      
     
    if(Zero == 1){
        for(i=0;i<n;++i){
            printf("%d",i);
            if(E[i].first->nxt!=NULL){
                printf(" ");
                GL now=E[i].first->nxt;
                for(;now!=NULL;now=now->nxt){
                    printf("%d",now->v);
                    if(now->nxt!=NULL)
                        printf(",");
                }
            }
            if(i!=n-1)
                printf("\n");
        }
    }
    else{
        for(i=1;i<=n;++i){
            printf("%d",i);
            if(E[i].first->nxt!=NULL){
                printf(" ");
                GL now=E[i].first->nxt;
                for(;now!=NULL;now=now->nxt){
                    printf("%d",now->v);
                    if(now->nxt!=NULL)
                        printf(",");
                }
            }
            if(i!=n)
                printf("\n");
        }                   
    }
    return 0;
}

