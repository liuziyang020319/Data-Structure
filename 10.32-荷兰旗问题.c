#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[4]={};
int x;
int main(){
    while(scanf("%d",&x)!=EOF){
        a[x]++;
    }
    int i = 0,flag=0;
    for(i=1;i<=a[1];i++){
        if(flag)printf(" ");
        printf("1");
        flag=1;
    }
    for(i=1;i<=a[2];i++){
        if(flag)printf(" ");
        printf("2");
        flag=1;
    }
    for(i=1;i<=a[3];i++){
        if(flag)printf(" ");
        printf("3");
        flag=1;
    }
    return 0;
}
