#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int data;
    struct Node * lson;
    struct Node * rson;
} * PT;
PT root = NULL;
int Target;
void Insert(int x){

    if(root == NULL){
		
        root = malloc(sizeof(struct Node));
        root->data = x;
        root->lson = NULL;
        root->rson = NULL;
        return;   
    }
    	
    PT now = root;
    while(1){
        if(x==now->data)break;
        if(x<now->data){
            if(now->lson == NULL){
                PT tmp = malloc(sizeof(struct Node));
                now->lson = tmp;
                tmp->data = x;
                tmp->lson = tmp->rson = 0;
                return ;
            }
            now = now->lson;
        }
        else{
            if(now->rson == NULL){
                PT tmp = malloc(sizeof(struct Node));
                now->rson = tmp;
                tmp->data = x;
                tmp->lson = tmp->rson = 0;
                return ;                
            }
            now=now->rson;
        }
    }
}
int ans[100010];
void DFS(PT now){
    if(now->lson!=NULL)DFS(now->lson);
    ans[++ans[0]]=now->data;
    if(now->rson!=NULL)DFS(now->rson);
}
int main(){
    char ch=getchar();
    int cnt=0;
    while(1){
        int x=0;
        int flag=1;
        while(ch<'0'||ch>'9'){
            if(ch == '-')flag=-1;
            ch=getchar();
        }        
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getchar();
        }
        x=x*flag;
        if(x!=-1)Insert(x);
        if(ch=='\n')cnt++;
        if(ch==EOF||cnt==2)break; 
    }
    DFS(root);
	int i = 1;
    for(;i<=ans[0];i++){
        printf("%d",ans[i]);
        if(i!=ans[0])printf(" ");
    }
    return 0;
}
