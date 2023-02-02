#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int flag;
    struct Node * vis[26];
} * PT;
PT root=NULL;
void Init(){
    root=malloc(sizeof(struct Node));
    int i;
    root->flag=0;
    for(i=0;i<26;++i)root->vis[i]=NULL;
}
void Insert(char s[]){
    int len=strlen(s);
    PT now=root;
    int i=0;
    for(;i<len;i++){    
       if(now->vis[s[i]-'a']==NULL){
           now->vis[s[i]-'a']=malloc(sizeof(struct Node));
           int j;
           now->flag=0;
           for(j=0;j<26;++j)now->vis[s[i]-'a']->vis[j]=NULL;
       } 
       
       now=now->vis[s[i]-'a'];
    }
    now->flag=1;
}
void Delete(char s[]){
    int len=strlen(s);
    PT now=root;
    int i=0;
    for(;i<len;i++){
       now=now->vis[s[i]-'a'];
    }    
    now->flag=0;
}
int Check(char s[]){
    int len=strlen(s);
    PT now=root;
    int i=0;
    for(;i<len;i++){
       if(now->vis[s[i]-'a']==NULL){
           return 0;
       } 
       now=now->vis[s[i]-'a'];
    }
    return now->flag;
}
int ans[1000];
int cnt=0;
int main(){
    Init();
    char s[1010];
    int idx;
    while(scanf("%d%s",&idx,s)!=EOF){
        if(idx==1)Insert(s);
        if(idx==2)Delete(s);
        if(idx==3){
            if(Check(s)==1)ans[++cnt]=1;
            else ans[++cnt]=0;
        }
    }
    int i=0;
    for(i=1;i<=cnt;++i){
        if(ans[i]==1)printf("True");
        else printf("False");
        if(i!=cnt)printf("\n");
    }
    return 0;
}