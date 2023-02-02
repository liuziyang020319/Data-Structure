#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PolyNode{
   int sum;
  struct PolyNode *next;
}PolyNode;
struct PolyNode * init(int sum){
	struct PolyNode *now=malloc(sizeof(struct PolyNode));
	memset(now,0,sizeof(struct PolyNode));
	now->sum=sum;
	now->next=NULL;
	return now;	
}
struct PolyNode * ins(struct PolyNode *head,int sum){
	if(head==NULL){
		return init(sum);
	}
	struct PolyNode *now=malloc(sizeof(struct PolyNode)),*pre;
	memset(now,0,sizeof(struct PolyNode));
	now->sum=sum;
	pre=head;
	while(pre->next!=NULL){
		pre=pre->next;
	}
	now->next=pre->next;
	pre->next=now;
	return head;
}
struct PolyNode * Merge(struct PolyNode *ha,struct PolyNode *hb){
	struct PolyNode *a=ha, *b=hb;
	while(a->next!=NULL&&b->next!=NULL){
		a=a->next;
		b=b->next;
	}
	if(a->next==NULL){
		a->next=hb;
		return ha;
	}
	else{
		b->next=ha;
		return hb;
	}
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
	}while(pre!=NULL);
}
char c;
int n,m,x,i;
int main(){
	struct PolyNode * ha=NULL, * hb=NULL, *hc=NULL;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		ha=ins(ha,x);
	}
	for(i=1;i<=m;++i){
		scanf("%d",&x);
		hb=ins(hb,x);
	}
	hc=Merge(ha,hb);
	Print(hc);
    return 0;
} 
