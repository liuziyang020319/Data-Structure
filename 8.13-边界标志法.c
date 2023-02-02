#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int begin,end,len;
    struct Node * nxt;
} * PT;
PT Head = NULL;
void add(int S,int len){
    PT now = malloc(sizeof(struct Node));
    memset(now,0,sizeof(struct Node));
    now->begin=S;
    now->end=S+len;
    now->len=len;
    now->nxt=NULL;
    PT pre=Head;
    for(;pre->nxt!=NULL&&pre->nxt->begin<now->begin;pre=pre->nxt);
    now->nxt=pre->nxt;
    pre->nxt=now;
}

int head[10010];
int siz[10010];
int tail[10010];
int hd;

void Merge(){
    PT now = Head->nxt;
    for(;now!=NULL&&now->nxt!=NULL;){
        if(now!=NULL&&now->nxt!=NULL&&now->end==now->nxt->begin){
            now->end=now->nxt->end;
            now->len=now->len+now->nxt->len;
            now->nxt=now->nxt->nxt;
        }
        else{
            now=now->nxt;
        }
    }
}
int tag,S,len;
int main(){
    Head = malloc(sizeof(struct Node));
    memset(Head,0,sizeof(struct Node));
    Head->nxt=NULL;
    char ch=getchar();
    while(ch=='0'){
        scanf("%d %d\n",head+hd,siz+hd);
        tail[hd]=siz[hd]+head[hd];
        hd++;
        // add(S,len);
        ch=getchar();
    }
    int i,j;
    for(i=0;i<hd-1;i++){
        for(j=hd-1;j>i;j--){
            if(head[j]<head[j-1]){
                int tmp=head[j-1];
                head[j-1]=head[j];
                head[j]=tmp;
                tmp=siz[j-1];
                siz[j-1]=siz[j];
                siz[j]=tmp;
                tmp=tail[j-1];
                tail[j-1]=tail[j];
                tail[j]=tmp;
            }
        }
    }

    if(ch!='1'&&ch!=EOF){
        ch=getchar();
    }
    while(ch=='1'){
        scanf("%d %d",&S,&len);
        int T=S+len;
        int i=0,j;
        for(;i<hd;i++){
            if(tail[i]==S){
                if(i+1<hd&&head[i+1]==T){
                    siz[i]+=len+siz[i+1];
                    tail[i]=head[i]+siz[i];
                    for(j=i+1;j<hd-1;j++){
                        head[j]=head[j+1];
                        siz[j]=siz[j+1];
                        tail[j]=tail[j+1];
                    }
                    hd--;
                }else{
                    siz[i]+=len;
                    tail[i]=head[i]+siz[i];
                }
                break;
            }else if(head[i]>S){
                if(head[i]==T){
                    head[i]=S;
                    siz[i]+=len;
                }else{
                    for(j=hd-1;j>=i;j--){
                        head[j+1]=head[j];
                        siz[j+1]=siz[j];
                        tail[j+1]=tail[j];
                    }
                    head[i]=S;
                    siz[i]=len;
                    tail[i]=T;
                    hd++;
                }break;
            }
        }
        if(i==hd){
            head[hd]=S;
            siz[hd]=len;
            tail[hd]=T;
            hd++;
        }        
        if(getchar()!='\n') break;
        ch=getchar();
    }
    for(i=0;i<hd;++i){
        printf("0 %d %d",head[i],siz[i]);
        if(i!=hd-1)printf("\n");
    }
    return 0;
}

