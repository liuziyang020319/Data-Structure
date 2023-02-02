#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char c;
int i;
typedef struct PolyNode{
   char sum;
  struct PolyNode *next;
}PolyNode;
struct PolyNode * init(char sum){
	struct PolyNode *now=malloc(sizeof(struct PolyNode));
	memset(now,0,sizeof(struct PolyNode));
	now->sum=sum;
	now->next=NULL;
	return now;	
}
struct PolyNode * ins(struct PolyNode *head,char sum){
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
struct PolyNode * del(struct PolyNode *head,char idx){
	struct PolyNode *ret, *pre, *suc;
	if(idx==head->sum){
		ret=head->next;
		free(head);
		return ret;
	}
	pre=head;
	while(pre->next!=NULL&&pre->next->sum!=idx){
		pre=pre->next;
	}
	if(pre->next!=NULL)
		suc=pre->next->next;
	else suc=NULL;
	if(pre->next!=NULL)
		free(pre->next);
	pre->next=suc;
	return head;
}
void Print(struct PolyNode * head){
	struct PolyNode * pre=head;
	if(head==NULL){
		printf("NULL");
		return;
	}
	printf("%c",pre->sum);
	pre=pre->next;
	if(pre==NULL)return;
	do{
		printf(",%c",pre->sum);
		pre=pre->next;
	}while(pre!=NULL);
}
struct PolyNode * operate(struct PolyNode *ha,struct PolyNode *hb,struct PolyNode *hc){
	struct PolyNode *a=ha,*b=hb,*c=hc,*now,*ret=ha;
	while(a!=NULL){
		while(b!=NULL&&b->sum<a->sum){
			b=b->next;
		}
		while(c!=NULL&&c->sum<a->sum){
			c=c->next;
		}
		if(b!=NULL&&c!=NULL){
			if(a->sum==b->sum&&a->sum==c->sum){
				now=a->next;
				ret=del(ret,a->sum);
				a=now;				
			}
			else{
				a=a->next;
			}
		}
		else a=a->next;
	}
	return ret;
}
char s[1000+10];
int main(){
	struct PolyNode * ha=NULL,* hb=NULL,* hc=NULL;
	scanf("%s",s);
	for(i=0;i<strlen(s);++i){
		if(s[i]!=',')ha=ins(ha,s[i]);
	}
	scanf("%s",s);
	for(i=0;i<strlen(s);++i){
		if(s[i]!=',')hb=ins(hb,s[i]);
	}
	scanf("%s",s);
	for(i=0;i<strlen(s);++i){
		if(s[i]!=',')hc=ins(hc,s[i]);
	}
	ha=operate(ha,hb,hc); 
	Print(ha);
    return 0;
} 
