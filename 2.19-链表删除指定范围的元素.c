#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char c;
int x,L,R;
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
struct PolyNode * del(struct PolyNode *head){
	struct PolyNode *now=head,*ha=head,*pre;
	while(now!=NULL){
		if(now->sum>L&&now->sum<R){
			if(now==ha){
				ha=now->next;
				free(now);
				now=ha;
			}
			else{
				pre=ha;
				while(pre->next!=now){
					pre=pre->next;
				}
				pre->next=now->next;
				free(now);
				now=pre;
			}
		}
		else
			now=now->next;
	}
	return ha;
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
int main(){
	struct PolyNode * head=NULL;
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
		head=ins(head,sum);
		if(c=='\n'||c==EOF)break;
	}
	scanf("%d %d",&L,&R);
	head=del(head);
	Print(head);
    return 0;
} 
