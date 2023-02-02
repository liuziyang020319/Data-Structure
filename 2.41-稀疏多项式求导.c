#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct PolyTerm{
	int sum,power;
}PolyTerm;
typedef struct PolyNode{
   struct PolyTerm data;
  struct PolyNode *next;
}PolyNode, *PolyLink;
struct PolyNode * init(int sum,int power){
	struct PolyNode *now=malloc(sizeof(struct PolyNode));
	memset(now,0,sizeof(struct PolyNode));
	now->data.sum=sum;
	now->data.power=power;
	now->next=NULL;
	return now;	
}
struct PolyNode * ins(struct PolyNode *head,int sum,int power){
	if(head==NULL){
		return init(sum,power);
	}
	struct PolyNode *now=malloc(sizeof(struct PolyNode)),*pre;
	memset(now,0,sizeof(struct PolyNode));
	now->data.sum=sum;
	now->data.power=power;
	pre=head;
	if(head->data.power<now->data.power){
		now->next=head;
		return now;
	}
	else{
		if(head->data.power==power){
			head->data.sum+=sum;
			return head;
		}
		while(pre->next!=NULL&&pre->next->data.power>now->data.power){
			pre=pre->next;
		}
		if(pre->next!=NULL&&pre->next->data.power==now->data.power){
			pre->next->data.sum+=sum;
			return head;
		}
		now->next=pre->next;
		pre->next=now;
		return head;
	}
}
struct PolyNode * del(struct PolyNode *now){
	struct PolyNode * pre=now;
	if(now->next==now){
		free(now);
		return NULL;	
	}
	while(pre->next!=now){
		pre=pre->next;
	}
	pre->next=now->next;
	free(now);
	return pre;
}
void convert(struct PolyNode *head){
	struct PolyNode * pre=head;
	if(head==NULL)return;
	while(pre->next!=NULL){
		pre=pre->next;
	}
	pre->next=head;
}
struct PolyNode * derivation(struct PolyNode * head){
	if(head==NULL)return NULL;
	struct PolyNode * now=head;
	do{
		now->data.sum*=now->data.power;
		now->data.power-=(now->data.power!=0);
		now=now->next;
	}while(now!=head);
	do{
		if(now->data.sum==0){
			now=del(now);
		}
		if(now==NULL)break;
		now=now->next;
	}while(now!=head&&now!=NULL);
	if(now==NULL)return NULL;
	else return head;
}
void Print(struct PolyNode * head){
	struct PolyNode * pre=head;
	do{
		struct PolyTerm now=pre->data;
		if(now.sum<0){
			printf("- ");
			now.sum=-now.sum;
		}
		else{
			if(pre!=head)
				printf("+ ");
		}
		printf("%d",now.sum);
		if(now.power!=0){
			printf("x");
			if(now.power>1){
				printf("^");
				printf("%d",now.power);
			}
		}
		if(pre->next!=head)
			printf(" ");
		pre=pre->next;
	}while(pre!=head);
}
char c;
int stack[10000];
int main(){
	struct PolyNode * head=NULL;
	int current=1;
	while((c=getchar())!=EOF&&c!='\n'){
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
		stack[++stack[0]]=x;
		if(current==2){
			int power=stack[stack[0]--];
			int sum=stack[stack[0]--];
			head=ins(head,sum,power);
			current=1;
		}
		else{
			if(c=='x'){
				c=getchar();
				if(c=='^'){
					current=2;
				}
				else{
					int sum=stack[stack[0]--];
					head=ins(head,sum,1);
				}
				if(c=='\n'||c==EOF)break;
			}
			else{
				int sum=stack[stack[0]--];
				head=ins(head,sum,0);				
			}			
		}
		if(c=='\n'||c==EOF)break;
	}
	convert(head);
	head=derivation(head);
	if(head==NULL){
		printf("0");
	}
	else{
		Print(head);
	}
	return 0;
}
