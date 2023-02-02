#include<stdio.h>
int a[100+10][100+10],n,m,tot=0;
int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j){
            scanf("%d",&a[i][j]);
            tot+=(a[i][j]!=0); 
        }
    }
    for(i=n-1;i>=0;--i){
        for(j=m-1;j>=0;--j){
            if(a[i][j]){
                if(a[i][j]!=1)printf("%d",a[i][j]);
                if(i!=0)printf("xE%d",i);
                if(j!=0)printf("yE%d",j);
                tot--;
                if(tot)printf("+");
            }
        }
    }
    return 0;
}
