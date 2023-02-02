#include<stdio.h>
char s[1000+10],t[1000+10];
int nxtval[1000+10];
int i,j;
void GetNXT(char t[],int nxt[]){
    nxt[1]=0;
    i=1,j=0;
    while(i<t[0]){
        if(j==0||t[i]==t[j]){
			i++;j++;
			if(t[i]!=t[j]){nxtval[i]=j;}else{nxtval[i]=nxtval[j];} 
		}
        else j=nxtval[j];	
    }
    for(i=0;i<=t[0];i++)printf("%d ",nxtval[i]);
}
int GetPos(char s[],char t[]){
    i=1;j=1;
    while(i<=s[0]&&j<=t[0]){
        if(j==0||s[i]==t[j]){i++;j++;}
        else j=nxtval[j];
    }
    if(j>t[0])return i-t[0]-1; 
    else return -1;
}
int main(){
    scanf("%d%d",&s[0],&t[0]);getchar();
    for(i=1;i<=s[0];++i)scanf("%c",&s[i]);getchar();
    for(i=1;i<=t[0];++i)scanf("%c",&t[i]);
    GetNXT(t,nxtval);
    printf("%d",GetPos(s,t));
    return 0;
}
