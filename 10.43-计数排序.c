#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXINT 1000010
unsigned short cnt[MAXINT];
int sum[10010],x;
int main(){
    while(scanf("%d",&x)!=EOF){
        sum[++sum[0]]=x;
        cnt[x]++;
    }    
    int i=1;
    for(;i<MAXINT;++i){
        cnt[i]+=cnt[i-1];
    }
    for(i=1;i<=sum[0];++i){
        printf("%d",cnt[sum[i]]-1);
        if(i!=sum[0])printf(" ");
    }
    return 0;
}