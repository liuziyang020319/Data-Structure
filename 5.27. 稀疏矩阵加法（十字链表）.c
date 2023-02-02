#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int x,y,sum;
    struct Node *right,*down;
}Node,Asum[1000+10],Bsum[1000+10];
typedef struct Node* CNODE;
struct CList{
    int n,m,tot;
    CNODE Row[1000],Col[1000];
}CLA,CLB;
int n,m;
int cntA,cntB;
int A[1000+10][1000+10];
int B[1000+10][1000+10];
void init(struct CList *CL){
    int i;
    CL->n=n;
    CL->m=m;
    CL->tot=0;
    for(i=0;i<=n;++i)CL->Col[i]=NULL;
    for(i=0;i<=m;++i)CL->Row[i]=NULL;
}
void BuildA(){
    int i,j;
    for(i=1;i<=cntA;++i){
        CNODE P= malloc(sizeof(Node));
        P->x=Asum[i].x;
        P->y=Asum[i].y;
        P->sum=Asum[i].sum;
        if(CLA.Row[P->y]==NULL||CLA.Row[P->y]->x>P->x){
            P->down=CLA.Row[P->y];
            CLA.Row[P->y]=P;
        }
        else{
            CNODE now=CLA.Row[P->y];
            for(;now->down!=NULL&&now->down->x<P->x;now=now->down);
            P->down=now->down;
            now->down=P;
        }
        if(CLA.Col[P->x]==NULL||CLA.Col[P->x]->y>P->y){
            P->right=CLA.Col[P->x];
            CLA.Col[P->x]=P;
        }
        else{
            CNODE now=CLA.Col[P->x];
            for(;now->right!=NULL&&now->right->y<P->y;now=now->right);
            P->right=now->right;
            now->right=P;
        }
    }
}
void BuildB(){
    int i,j;
    for(i=1;i<=cntB;++i){
        CNODE P= malloc(sizeof(Node));
        P->x=Bsum[i].x;
        P->y=Bsum[i].y;
        P->sum=Bsum[i].sum;
        if(CLB.Row[P->y]==NULL||CLB.Row[P->y]->x>P->x){
            P->down=CLB.Row[P->y];
            CLB.Row[P->y]=P;
        }
        else{
            CNODE now=CLB.Row[P->y];
            for(;now->down!=NULL&&now->down->x<P->x;now=now->down);
            P->down=now->down;
            now->down=P;
        }
        if(CLB.Col[P->x]==NULL||CLB.Col[P->x]->y>P->y){
            P->right=CLB.Col[P->x];
            CLB.Col[P->x]=P;
        }
        else{
            CNODE now=CLB.Col[P->x];
            for(;now->right!=NULL&&now->right->y<P->y;now=now->right);
            P->right=now->right;
            now->right=P;
        }
    }
}
void ins(CNODE P){
	CLA.tot++;
    if(CLA.Row[P->y]==NULL||CLA.Row[P->y]->x>P->x){
        P->down=CLA.Row[P->y];
        CLA.Row[P->y]=P;
    }
    else{
        CNODE now=CLA.Row[P->y];
        for(;now->down!=NULL&&now->down->x<P->x;now=now->down);
        P->down=now->down;
        now->down=P;
    }
    if(CLA.Col[P->x]==NULL||CLA.Col[P->x]->y>P->y){
        P->right=CLA.Col[P->x];
        CLA.Col[P->x]=P;
    }
    else{
        CNODE now=CLA.Col[P->x];
        for(;now->right!=NULL&&now->right->y<P->y;now=now->right);
        P->right=now->right;
        now->right=P;
    }
}
void Del(CNODE P){
    CLA.tot--;
    CNODE now=CLA.Row[P->y];
    if(now==P)CLA.Row[P->y]=now->down;
    else{
        for(;now->down!=P;now=now->down);
        now->down=P->down;
    }
    now=CLA.Col[P->x];
    if(now==P)CLA.Col[P->x]=now->right;
    else{
        for(;now->right!=P;now=now->right);
        now->right=P->right;
    }
}
void Cal(){
    int i;
    for(i=1;i<=n;++i){
        CNODE nowA=CLA.Col[i];
        CNODE nowB=CLB.Col[i];
        for(;nowA!=NULL;nowA=nowA->right){
            for(;nowB!=NULL&&nowB->y<nowA->y;nowB=nowB->right){
                CNODE tmp= malloc(sizeof(Node));
                memset(tmp,0,sizeof(Node));
                tmp->x=nowB->x;
                tmp->y=nowB->y;
                tmp->sum=nowB->sum;
                ins(tmp);
            }
            if(nowB!=NULL&&nowB->y==nowA->y){
                nowA->sum+=nowB->sum;
                if(nowA->sum==0)Del(nowA);
                nowB=nowB->right;
            }
        }
        for(;nowB!=NULL;nowB=nowB->right){
            CNODE tmp= malloc(sizeof(Node));
            memset(tmp,0,sizeof(Node));
            tmp->x=nowB->x;
            tmp->y=nowB->y;
            tmp->sum=nowB->sum;           
            ins(tmp); 
        }
    }
}
int vis[1001][1001];
void Print(){
	int tot=0;
	int i,j;
	for(i=1;i<=n;++i){
		if(CLA.Col[i]!=NULL){
			CNODE now=CLA.Col[i];
            for(;now!=NULL;now=now->right){
                ++tot;
                vis[now->x][now->y]=1;
                if(tot!=CLA.tot)printf("%d ",now->sum);
                else printf("%d\n",now->sum);
            }
		}
	}
	if(CLA.tot==0)puts("");
    for(i=1;i<=n;++i){
        for(j=1;j<m;++j){
            printf("%d ",vis[i][j]);
        }
        printf("%d\n",vis[i][j]);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    init(&CLA);
    init(&CLB);
    int x;
    char c;
    c=getchar();
    while((c=getchar())!='\n'){
        int flag=1;
        x=0;
        while((c<'0'||c>'9')&&c!='\n'){
            if(c=='-')flag=-1;
            c=getchar();
        }
        if(c=='\n')break;
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        x=x*flag;
        Asum[++cntA].sum=x;
        if(c=='\n')break;
    }
    int i,j,tot;

    for(tot=0,i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&A[i][j]);
            if(A[i][j]){
                ++tot;
                Asum[tot].x=i;
                Asum[tot].y=j;
            }
        }
    }    
    CLA.tot=cntA;
    BuildA();
    c=getchar();
    while((c=getchar())!='\n'){
        int flag=1;
        x=0;
        while((c<'0'||c>'9')&&c!='\n'){
            if(c=='-')flag=-1;
            c=getchar();
        }
        if(c=='\n')break;
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        x=x*flag;
        Bsum[++cntB].sum=x;
        if(c=='\n')break;
    } 
    for(tot=0,i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&B[i][j]);
            if(B[i][j]){
                ++tot;
                Bsum[tot].x=i;
                Bsum[tot].y=j;
            }
        }
    }
    CLB.tot=tot;
    BuildB();
    Cal();
    Print();
//    printf("%d",CLA.tot);
	return 0;
}
