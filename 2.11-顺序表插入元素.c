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
	if(head->sum>sum){
		now->next=head;
		return now;
	}
	else{
		while(pre->next!=NULL&&pre->next->sum<now->sum){
			pre=pre->next;
		}
		now->next=pre->next;
		pre->next=now;
		return head;
	}
}
void Print(struct PolyNode * head){
	struct PolyNode * pre=head;
	do{
		printf("%d ",pre->sum);
		pre=pre->next;
	}while(pre!=NULL);
}
char c;
int x;
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
    scanf("%d",&x);
    head=ins(head,x);
	Print(head);
    return 0;
}
