#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node * nxt;
    struct Node * tail;
} * PT;
PT r[10];
PT head;
void Init(){
    head=malloc(sizeof(struct Node));
    head->key=0;
    head->nxt=NULL;
    head->tail=NULL;
}
void Insert(PT head,int key){
    head->key++;    
    PT now=malloc(sizeof(struct Node));
    now->key=key;
    now->nxt=NULL;
    now->tail=NULL;
    if(head->nxt==NULL){
        head->nxt=now;
        head->tail=now;
    }
    else{
        head->tail->nxt=now;
        head->tail=now;
    }
}
void Radix_Sort(){
    int mod=1,i,j,k;
    for(i=0;i<=9;++i){
        r[i]=malloc(sizeof(struct Node));
        r[i]->key=0;
        r[i]->nxt=NULL;
        r[i]->tail=NULL;
    }
    for(i=1;i<=9;++i){
        mod=mod*10;
        for(j=0;j<=9;++j){
            r[j]->key=0;
            r[j]->nxt=NULL;
            r[j]->tail=NULL;
        }
        PT now=head;
        for(j=1;j<=head->key;j++){
            now=now->nxt;
            int R=now->key%mod/(mod/10);
            Insert(r[R],now->key);
        }
        head->key=0;
        head->nxt=NULL;
        head->tail=NULL;
        for(j=0;j<=9;++j){
            if(r[j]->key>0){
                PT now=r[j];
                for(k=1;k<=r[j]->key;++k){
                    now=now->nxt;
                    Insert(head,now->key);
                }               
            }
        }
    }
}
int x;
int main(){
    Init();
    while(scanf("%d",&x)!=EOF){
        Insert(head,x);
    }
    Radix_Sort();
    int i;
    PT now=head;
    for(i=1;i<=head->key;++i){
        now=now->nxt;
        printf("%d",now->key);
        if(i!=head->key)printf(" ");
    }
    return 0;
}
