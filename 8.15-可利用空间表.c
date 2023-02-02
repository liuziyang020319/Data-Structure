#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int LB,HB,len;
int a[100000+10];
int main(){
    scanf("%d %d %d",&LB,&HB,&len);
    int n=(HB-LB)/len;
    int i=0;
    for(;i<n;i++){
        scanf("%d",&a[i]);
    } 
    a[n]=1;
    int cnt=0;
    int S=LB;
    int flag=0;
    for(i=0;i<=n;i++){
        if(a[i]==1&&cnt){
            if(flag)printf("\n");
            printf("0 %d %d",S,cnt*len);
            flag=1;
            cnt=0;
        }
        else{
            if(a[i]==0){
                if(cnt==0){
                    cnt=1;
                    S=LB+i*len;
                }
                else{
                    cnt++;
                }
            }
        }
    }
    if(flag==0){
        printf("0 0 0");
    }
    return 0;
}