#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[1000+10];
char tar;
typedef enum{ATOM, LIST} ElemTag;
struct LNode{
    ElemTag tag;
    int siz;
    union {
        char data;
        struct LNode *head;
    };
    struct LNode *nxt;
}LNode;
typedef struct LNode* Node;
Node build(char *s){
//	printf("%s\n",s);
    if(strlen(s)==0){
        return NULL;
    }
    else{
        Node tmp;
		tmp=malloc(sizeof(LNode));
        Node ret=tmp;
        tmp->tag=LIST;
        tmp->siz=0;
        tmp->head=tmp->nxt=NULL;
        char *ch;
        ch=malloc((strlen(s)+2)*sizeof(char));
        int i;
        for(i=1;i<strlen(s)-1;i++){
            ch[i-1]=s[i];
        }
        ch[strlen(s)-1]='\0';
//        printf("%s\n",ch);
        int len=strlen(ch);
        int pos=0,pre=-1;
        do{
        	int cntC=0;
            while(pos<len&&!(cntC==0&&ch[pos]==',')){
				if(ch[pos]=='(')cntC++;
				if(ch[pos]==')')cntC--;
				pos++;
			}
//        	printf("%d %d\n",pre,pos);
            char *nxt=malloc((pos-pre+2)*sizeof(char));
            int i;
            for(i=pre+1;i<pos;++i){
                nxt[i-pre-1]=ch[i];
            }
            nxt[pos-pre-1]='\0';
            if(strlen(nxt)==1){
                Node num=malloc(sizeof(LNode));
                num->tag=ATOM;
                num->data=nxt[0];
                num->nxt=NULL;
                num->siz=(nxt[0]!=tar);
                ret->siz+=num->siz;
                tmp->head=num;
            }
            else{
                tmp->head=build(nxt);
                ret->siz+=tmp->head->siz;
            }
            if(pos<len){
                Node nxtNode=malloc(sizeof(LNode));
                tmp->nxt=nxtNode;
                tmp=nxtNode;
            }
            pre=pos;
            pos++;
        }while(pos<len);
        tmp->nxt=NULL;
        return ret;
    }
}
void Print(Node now){
    if(now==NULL){
        return;
    }
    if(now->siz==0)return;
    if(now->tag==ATOM){
        printf("%c",now->data);
        return;
    }
    printf("(");
    int tot=0;
    if(now->head->siz){
        Print(now->head);
        tot+=now->head->siz;
        if(tot<now->siz)printf(",");
    }
    Node tmp=now->nxt;
    for(;tmp!=NULL;tmp=tmp->nxt){
        if(tmp->head->siz){
            Print(tmp->head);
            tot+=tmp->head->siz;
            if(tot<now->siz)printf(",");
        }
    }
    printf(")");
}
int main(){
    scanf("%s %c",s,&tar);
    Node Star=build(s);
    if(Star->siz==0){
        printf("-1");
    }
    else Print(Star);
	return 0;
}
