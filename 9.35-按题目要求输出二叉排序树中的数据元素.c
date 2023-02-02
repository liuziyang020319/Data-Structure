#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int data;
    struct Node * lson;
    struct Node * rson;
} * PT;
PT root = NULL;
int L,R;
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
    if(now->data>L&&now->data<R)ans[++ans[0]]=now->data;  
    if(now->rson!=NULL)DFS(now->rson);
}
int main(){
    char ch=getchar();
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
        Insert(x);
        if(ch=='\n')break;
    }
    scanf("%d%d",&L,&R);
    DFS(root);
	int i = 1;
    for(;i<=ans[0];i++){
        printf("%d",ans[i]);
        if(i!=ans[0])printf(" ");
    }
    return 0;
}
