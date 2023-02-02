#include<stdio.h>
char s[1000+10],t[1000+10];
int nxt[1000+10];
int i,j;
void GetNXT(char t[],int nxt[]){
    nxt[1]=0;
    i=1,j=0;
    while(i<t[0]){
        if(j==0||t[i]==t[j]){i++;j++;nxt[i]=j;}
        else j=nxt[j];	
    }
}
int GetPos(char s[],char t[]){
    i=1;j=1;
    while(i<=s[0]&&j<=t[0]){
        if(j==0||s[i]==t[j]){i++;j++;}
        else j=nxt[j];
    }
    if(j>t[0])return i-t[0]-1; 
    else return -1;
}
int main(){
    scanf("%d%d",&s[0],&t[0]);getchar();
    for(i=1;i<=s[0];++i)scanf("%c",&s[i]);getchar();
    for(i=1;i<=t[0];++i)scanf("%c",&t[i]);
    GetNXT(t,nxt);
//    for(i=1;i<=t[0];++i){
//    	printf("%d ",nxt[i]);
//    }
//    puts("");
    printf("%d",GetPos(s,t));
    return 0;
}
