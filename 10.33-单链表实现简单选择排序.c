#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node * nxt;
} * PT;
PT head;
void Init(){
    head = malloc(sizeof(struct Node));
    head->key=0;
    head->nxt=NULL;
}
void Insert(int x){
    head->key++;
    PT pre=head;
    while(pre->nxt!=NULL)pre=pre->nxt;
    PT now = malloc(sizeof(struct Node));
    now->nxt=pre->nxt;
    now->key=x;
    pre->nxt=now;
}
void Del(PT head,int x){
    PT pre=head;
    while(pre->nxt!=NULL&&pre->nxt->key!=x)pre=pre->nxt;
    pre->nxt=pre->nxt->nxt;
}
void select_sort(){
    int n=head->key;
    int i=1,j;
    PT prenow=head;
    for(;i<=n;++i){
        PT min = prenow->nxt;
        PT pre = prenow->nxt;
        for(j=i;j<=n;++j){            
            if(pre->key<min->key)min=pre;
            if(j!=n)pre=pre->nxt;
        }
        Del(prenow,min->key);
        min->nxt=prenow->nxt;
        prenow->nxt=min;
        prenow=min;
    }
    PT now=head;
    for(i=1;i<=n;++i){
        now=now->nxt;
        printf("%d",now->key);
        if(i!=n)printf(" ");
    }
}
int x;
int main(){
    Init();
    while(scanf("%d",&x)!=EOF){
        Insert(x);
    }       
    select_sort();
    return 0;
}
