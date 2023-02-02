#include<stdio.h>
#include<string.h>
char s[1000+10],t[1000+10];
int nxt[1000+10];
int ans=0;
int pos;
void GetNXT(char t[],int nxt[],int idx){
    nxt[1]=0;
    int i=1,j=0;
    while(i<t[0]){
        if(j==0||t[i]==t[j]){i++;j++;nxt[i]=j;}
        else j=nxt[j];	
    }
    for(i=1;i<=t[0];++i){
        if(ans<nxt[i]-1){
            ans=nxt[i]-1;
            pos=idx;
        }
    }
}
char c;
int main(){
    s[0]=0;
    while((c=getchar())!='\n'&&c!=EOF){
        s[++s[0]]=c;
    }
    s[++s[0]]='\0'; 
    int i,j;
    for(i=1;i<=s[0];++i){
        t[0]=s[0]-i+1;
        for(j=i;j<=s[0];++j){
            t[j-i+1]=s[j];
        }
        GetNXT(t,nxt,i);
    }
    if(ans==0){
    	printf("-1");
    	return 0;
    }
    for(i=1;i<=ans;++i){
    	putchar(s[pos+i-1]);
    }
    printf(" %d",pos-1);
    return 0;
}
