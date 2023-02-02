#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int OPERATE[7][7]={{0, 0, 0, 0, 0, 0, 0},
                   {0, 1, 1,-1,-1,-1, 1},
                   {0, 1, 1,-1,-1,-1, 1},
                   {0, 1, 1, 1, 1,-1, 1},
                   {0, 1, 1, 1, 1,-1, 1},
                   {0,-1,-1,-1,-1,-1, 0},
                   {1, 1, 1, 1, 1, 0, 1}
                  };
int mapping(char c){
    int opt=0;
    switch (c){
        case '+': 
			opt=1; break;
        case '-': 
			opt=2; break;
        case '*': 
			opt=3; break;
        case '/':
			opt=4; break;
        case '(': 
			opt=5; break;
        case ')': 
			opt=6; break;   
	} 
    return opt;
}
typedef struct Stack{
    int s[1000];
    int top;
}Stack, *StackPointer;
typedef StackPointer SP;
SP OPTR,OPND;
SP init(){
    SP ret=malloc(sizeof(Stack));
    memset(ret,0,sizeof(Stack));
    ret->top=-1;
    return ret;
}
int top(SP now){
    return now->s[now->top];
}
void pop(SP now){
    now->top--;
}
void ins(SP now,int x){
    now->s[++now->top]=x;
}
int empty(SP now){
    return (now->top==-1);
}
int i;
char s[10000+10];
void reverse(char *a){
    int len=strlen(a),i;
    char c[1001];
    for(i=0;i<len;++i){
        c[i]=a[len-i-1];
    }
    for(i=0;i<len;++i){
        a[i]=c[i];
    }
}
int main(){
    OPTR=init();
    OPND=init();
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<len;++i){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')){
            ins(OPND,s[i]);
        }
        else{
            int opt=mapping(s[i]);
			while(1){
	            if(empty(OPTR)){
	                ins(OPTR,s[i]);
	                break;
	            }
	            else{
	                if(opt==6){
	                    while(mapping(top(OPTR))!=5){
	                        ins(OPND,top(OPTR));
	                        pop(OPTR);
	                    }
	                    pop(OPTR);
	                    break;
	                }
	                int now=mapping(top(OPTR));
	                if(OPERATE[now][opt]==1){
	                    ins(OPND,top(OPTR));
	                    pop(OPTR);
	                }
	                else{
	                    ins(OPTR,s[i]);
	                    break;
	                }
	            }				
			}
        }
    }
    while(!empty(OPTR)){
        ins(OPND,top(OPTR));
        pop(OPTR);
    }
    char ans[1000+10];
    int idx=0;
    while(!empty(OPND)){
        ans[idx++]=top(OPND);
        pop(OPND);
    }
    ans[idx]='\0';
    reverse(ans);
    printf("%s",ans);
    return 0;
}
