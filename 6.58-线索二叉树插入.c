#include<stdio.h>
#include<string.h>
#include<stdlib.h>
enum TYPE {Link,Thread};
typedef struct CTNODE{
    struct CTNODE * lson;
    struct CTNODE * rson;
    int idx;
    enum TYPE Ltag,Rtag;
}* NODEptr,CTNODE;
NODEptr Tree[1000+10];
int L[1000+10],lcnt=-1;
int R[1000+10],rcnt=-1;
int ans[1000+10];
int n,root,pos,offset;
char c;
void DFS1(int idx,NODEptr now);
NODEptr GetNode(){
    NODEptr ret = malloc(sizeof(CTNODE));
    memset(ret,0,sizeof(CTNODE));
    return ret;
}
NODEptr pre;
NODEptr GetOrder(int root){
    NODEptr Rt=GetNode();
    Rt->idx=-1;
    Rt->Ltag=Link;
    Rt->Rtag=Thread;
    Rt->rson=Rt;
    if(!root)Rt->lson=Rt;
    else{
        Rt->lson=GetNode();
        pre=Rt;
        DFS1(root,Rt->lson);
        pre->rson=Rt;
        pre->Rtag=Thread;
        Rt->rson=pre;
    }
    return Rt;
}
void DFS1(int idx,NODEptr now){
    now->idx=(idx<=n)?idx:idx+offset-n-1;
    if(L[idx]){
        now->Ltag=Link;
        now->lson=GetNode();
        DFS1(L[idx],now->lson);
    }
    else{
        now->Ltag=Thread;
        now->lson=pre;
        pre->rson=now;
    }
    pre=now;
    ans[++ans[0]]=now->idx;
    if(R[idx]){
        now->Rtag=Link;
        now->rson=GetNode();
        DFS1(R[idx],now->rson);
    }
}
int main(){
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        L[++lcnt]=0;
        while(c>='0'&&c<='9'){
            L[lcnt]=L[lcnt]*10+c-'0';
            c=getchar();
        }
        if(c=='\n')break;
    }
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        R[++rcnt]=0;
        while(c>='0'&&c<='9'){
            R[rcnt]=R[rcnt]*10+c-'0';
            c=getchar();
        }
        if(c=='\n')break;
    }
    scanf("%d",&pos);
    root=L[0];
    n=lcnt;
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        L[++lcnt]=0;
        while(c>='0'&&c<='9'){
            L[lcnt]=L[lcnt]*10+c-'0';
            c=getchar();
        }
        if(c=='\n')break;
    }    
    c=getchar();
    while(1){
        while(c<'0'||c>'9'){
            c=getchar();
        }
        R[++rcnt]=0;
        while(c>='0'&&c<='9'){
            R[rcnt]=R[rcnt]*10+c-'0';
            c=getchar();
        }
        if(c=='\n'||c==EOF)break;
    }
    int i;
    offset=L[n+1]-1;
    for(i=n+2;i<=lcnt;++i){
        if(L[i])L[i]=L[i]-offset+n+1;
        if(R[i])R[i]=R[i]-offset+n+1;
    }
    R[n+2]=L[pos];
    L[pos]=L[n+1]-offset+n+1;
    NODEptr RT= GetOrder(root);
    for(i=1;i<ans[0];++i)printf("%d ",ans[i]);
    printf("%d",ans[ans[0]]);
    return 0;
}
