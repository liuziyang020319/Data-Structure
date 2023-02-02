#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct StackNode{
	int n;
	struct StackNode * next;
}StackNode,*top;
struct StackNode * init(int n){
	struct StackNode * top=malloc(sizeof(StackNode));
	memset(top,0,sizeof(StackNode));
	top->n=n;
	top->next=NULL;
	return top;
}
struct StackNode * ins(struct StackNode * top,int n){
	if(top==NULL)return init(n);
	struct StackNode * pre=top;
	struct StackNode * now=malloc(sizeof(StackNode));
	memset(now,0,sizeof(StackNode));
	now->n=n;
	now->next=NULL;
	while(pre->next!=NULL){
		pre=pre->next;
	}
	pre->next=now;
	return top;
}
int empty(struct StackNode * top){
	return top==NULL;
}
int Top(struct StackNode * top){
	return top->n;
}
struct StackNode * Pop(struct StackNode * top){
	if(empty(top))return NULL;
	struct StackNode * ret=top->next;
	free(top);
	return ret;
}
int n;
int main(){
	struct StackNode * top=NULL;
	scanf("%d",&n);
	while(n){
		top=ins(top,n);
		n>>=1;
	}
	int ans=1;
	while(!empty(top)){
		ans=ans*Top(top);
		top=Pop(top);
	}
	printf("%d",ans);
	return 0;
}
