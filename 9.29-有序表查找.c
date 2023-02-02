#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int key;
    struct Node * nxt;
} * PT;
PT Head;
void Init(){
    Head = malloc(sizeof(struct Node));
    Head->key=0;
    Head->nxt=NULL;
}
void add(int key){
    PT pre = Head;
    while(pre->nxt!=NULL&&pre->nxt->key<key){
        pre=pre->nxt;
    }
    PT now=malloc(sizeof(struct Node));
    now->nxt=pre->nxt;
    now->key=key;
    pre->nxt=now;
}
int Check(int x){
    PT now = Head->nxt;
    while(now!=NULL){
        if(now->key==x){
            return 1;
        }
        else{
            now=now->nxt;
        }
    }
    return 0;
}
int ans[100010];
int main(){
    Init();
    
    char ch=getchar();
    while(1){
        int x=0,flag=1;
        while(ch<'0'||ch>'9'){
            if(ch=='-')flag=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getchar();
        }
        x=x*flag;
        add(x);
        if(ch=='\n'||ch==EOF)break;
    }
    while(1){
        int x=0,flag=1;
        while(ch<'0'||ch>'9'){
            if(ch=='-')flag=-1;
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getchar();
        }
        x=x*flag;
        ans[++ans[0]]=Check(x);
        if(ch=='\n'||ch==EOF)break;
    }
    int i;
    for(i=1;i<=ans[0];++i){
        printf("%d",ans[i]);
        if(i!=ans[0])printf(" ");
    }
    return 0;
}