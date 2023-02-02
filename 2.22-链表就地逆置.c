#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char c;
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
struct PolyNode * Reverse(struct PolyNode *head){
	struct PolyNode *now=head->next,*pre=head,*tmp;
	while(now!=NULL){
		tmp=now->next;
		now->next=pre;
		pre=now;
		now=tmp;
	}
	head->next=NULL;
	return pre;
}
void Print(struct PolyNode * head){
	struct PolyNode * pre=head;
	if(head==NULL){
		printf("NULL");
		return;
	}
	printf("%c",pre->sum);
	pre=pre->next;
	do{
		printf(",%c",pre->sum);
		pre=pre->next;
	}while(pre!=NULL);
}
int main(){
	struct PolyNode * head=NULL;
	while((c=getchar())!='\n'&&c!=EOF){
		if(c==',')continue;
		else head=ins(head,c);
	}
	head=Reverse(head);
	Print(head);
    return 0;
} 
