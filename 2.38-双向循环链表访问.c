#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i,n;
typedef struct PolyNode{
   int sum,freq,Tim;
  struct PolyNode *next, *pre;
}PolyNode;
struct PolyNode * init(int sum,int freq){
	struct PolyNode *now=malloc(sizeof(struct PolyNode));
	memset(now,0,sizeof(struct PolyNode));
	now->sum=sum;
	now->freq=freq;
	now->Tim=0;
	now->next=NULL;
	now->pre=NULL;
	return now;	
}
struct PolyNode * ins(struct PolyNode *head,int sum,int freq){
	if(head==NULL){
		return init(sum,freq);
	}
	struct PolyNode *now=malloc(sizeof(struct PolyNode)),*pre;
	memset(now,0,sizeof(struct PolyNode));
	now->sum=sum;
	now->freq=freq;
	now->Tim=0;
	pre=head;
	while(pre->next!=NULL){
		pre=pre->next;
	}
	now->next=pre->next;
	pre->next=now;
	now->pre=pre;
	return head;
}
struct PolyNode * Convert(struct PolyNode *head){
	struct PolyNode *now=head;
	while(now->next!=NULL){
		now=now->next;
	}
	now->next=head;
	head->pre=now;
	return head;
} 
struct PolyNode * Modify(struct PolyNode *head,int sum,int Tim){
	struct PolyNode * now=head,*pre;
	do{
		if(now->sum==sum){
			if(now->Tim==0)now->Tim=Tim;
			now->freq++;
			now->pre->next=now->next;
			now->next->pre=now->pre;
			if(now==head)head=now->next;
			pre=head;
			while((pre->freq>now->freq||(pre->freq==now->freq&&pre->Tim<now->Tim))&&pre->next!=head)
				pre=pre->next;
			if(pre->next==head&&(pre->freq>now->freq||(pre->freq==now->freq&&pre->Tim<now->Tim))){
				pre=pre->next;	
				now->pre=pre->pre;
				now->pre->next=now;	
				now->next=pre;
				pre->pre=now;
				return head;
			}
			now->pre=pre->pre;
			now->pre->next=now;	
			now->next=pre;
			pre->pre=now;
			if(pre==head)return now;
			else return head;	
			break;
		}
		now=now->next;
	}while(now!=head);
	return head;
}
void Print(struct PolyNode * head){
	struct PolyNode * pre=head;
	if(head==NULL){
		printf("NULL");
		return;
	}
	do{
		printf("%d ",pre->sum);
		pre=pre->next;
	}while(pre!=head);
}
struct PolyNode * operate(struct PolyNode *head){
	return ;
}
int main(){
	struct PolyNode * head=NULL;	
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		head=ins(head,x,0);
		if(n==1){
			printf("%d",x);
			return 0;	
		}
	}
	head=Convert(head);
	int Tim=0;
	char c;
	c=getchar();
	while((c=getchar())!='\n'){
		int x=0;
		int f=1;
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar();
		}
		while(c>='0'&&c<='9'){
			x=x*10+c-'0';
			c=getchar();
		}
		x*=f;
		int sum=x;
		head=Modify(head,sum,++Tim);
		if(c=='\n'||c==EOF)break;
	}
	Print(head);
    return 0;
}
