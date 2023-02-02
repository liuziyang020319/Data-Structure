#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int DX[4]={ 0,-1, 1, 0};
int DY[4]={ 1, 0, 0,-1};
struct QNode{
    int x,y,get,pre,id,step;
};
struct QNode Q[100000+10];
int head=0;
int tail=-1;
int RX,RY,n,m;
int YX,YY,CX,CY;
int G[100+10][100+10];
int inX(int x){
    return x>=1&&x<=n;
}
int inY(int y){
    return y>=1&&y<=m;
}
void PRINT(struct QNode now){
    if(now.pre!=-1)PRINT(Q[now.pre]);
    printf("%d %d\n",now.x,now.y);
    return;
}
void BFS(){
    struct QNode now;
    now.x=RX;
    now.y=RY;
    now.get=0;
    now.pre=-1;
    now.step=1;
    now.id=0;
    Q[++tail]=now;
    while(head<=tail){
        struct QNode tmp=Q[head];
        head++;
        if(tmp.x==CX&&tmp.y==CY&&tmp.get){
            PRINT(tmp);
            return;
        }
        int i;
        for(i=0;i<4;++i){
            int NX=tmp.x+DX[i];
            int NY=tmp.y+DY[i];
            if(!inX(NX)||!inY(NY))continue;
            if(G[NX][NY]==1)continue;
            struct QNode NXT;
            NXT.x=NX;
            NXT.y=NY;
            NXT.get=tmp.get;
            NXT.step=tmp.step+1;
            NXT.pre=tmp.id;
            NXT.id=tail+1;
            if(NX==YX&&NY==YY){
                NXT.get=1;
            }
            Q[++tail]=NXT;
        }
    }
}
char s[101];
int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%s",s+1);
        for(j=1;j<=m;++j){
            if(s[j]=='1')G[i][j]=1;
            else G[i][j]=0;
            if(s[j]=='R'){
                RX=i,RY=j;
            }
            if(s[j]=='Y'){
                YX=i,YY=j;
            }
            if(s[j]=='C'){
                CX=i,CY=j;
            }
        }
    }
    BFS();
    return 0;
}
