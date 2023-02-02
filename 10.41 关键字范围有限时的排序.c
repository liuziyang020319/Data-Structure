#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXINT 10010
unsigned short cnt[MAXINT];
int sum[10010],x;
int main(){
    // freopen("test.txt","r",stdin);
    while(scanf("%d",&x)!=EOF){
        sum[++sum[0]]=x;
        cnt[x]++;
    }    
    int i;
    int tot=0;
    for(i=0;i<MAXINT;++i){
        if(cnt[i]!=0){
            int j=1;
            for(;j<=cnt[i];++j){
                printf("%d",i);
                tot++;
                if(tot!=sum[0])printf(" ");
            }
        }
    }
    return 0;
}