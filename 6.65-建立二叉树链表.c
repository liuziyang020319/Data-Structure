#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct CTNODE{
    struct CTNODE * lson;
    struct CTNODE * rson;
    char data;
}* NODEptr,CTNODE;
int Getpos(char s[],char c){
    int pos=0;
    int len=strlen(s);
    for(;s[pos]!=c&&pos<len;++pos);
    return pos;
}
NODEptr GetNode(){
    NODEptr ret = malloc(sizeof(CTNODE));
    memset(ret,0,sizeof(CTNODE));
    return ret;
}
NODEptr DFS(char a[],char b[]){
    int lena=strlen(a);
    int lenb=strlen(b);
//    printf("%s %s $%d %d\n",a,b,lena,lenb);
    if(lena==0){
    	return NULL;
    }
	if(lena==1){
        NODEptr ret=GetNode();
        ret->data=a[0];
        return ret;
    }
    else{
        NODEptr ret=GetNode();
        ret->data=a[0];
        int pos=Getpos(b,a[0]);
        char * nxta_1=malloc((pos+10)*sizeof(char));
        char * nxtb_1=malloc((pos+10)*sizeof(char));
        int i;
        for(i=0;i<pos;++i)nxta_1[i]=a[1+i];
        nxta_1[pos]='\0';
        for(i=0;i<pos;++i)nxtb_1[i]=b[i];
        nxtb_1[pos]='\0';

        char * nxta_2=malloc((lena-pos+10)*sizeof(char));
        char * nxtb_2=malloc((lenb-pos+10)*sizeof(char));
        for(i=0;i<lena-pos-1;++i)nxta_2[i]=a[pos+i+1];
        nxta_2[lena-pos-1]='\0';
        for(i=0;i<lenb-pos-1;++i)nxtb_2[i]=b[pos+i+1];
        nxtb_2[lenb-pos-1]='\0';

        ret->lson=DFS(nxta_1,nxtb_1);
        ret->rson=DFS(nxta_2,nxtb_2);
        return ret;
    }
}
void PRINT(NODEptr now){
    if(now->lson)PRINT(now->lson);
    if(now->rson)PRINT(now->rson);
    printf("%c",now->data);
}
char a[1000+10];
char b[1000+10];
int main(){
    scanf("%s%s",a,b);
    NODEptr RT=DFS(a,b);
    PRINT(RT);
    return 0;
}
