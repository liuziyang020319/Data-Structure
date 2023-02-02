#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[10010];
int nxt[10010];
int n;
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    nxt[0]=1;
    for(i=2;i<=n;++i){
        int pre=0;
        while(nxt[pre]!=0&&a[nxt[pre]]<a[i]){
            pre=nxt[pre];
        }
        nxt[i]=nxt[pre];
        nxt[pre]=i;
    }
    int pre=nxt[0],cnt=0;
    while(pre!=0){
        ++cnt;
        printf("%d",a[pre]);
        if(cnt!=n)printf(" ");
        pre=nxt[pre];
    }
    return 0;
}