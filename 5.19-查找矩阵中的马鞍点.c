#include<stdio.h>
const int INF = 1e9;
int Line[1000+10],Row[1000+10];
int a[1000+10][1000+10];
int n,m,i,j;
int main(){
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;++i)Row[i]=INF;
    for(i=1;i<=m;++i)Line[i]=-INF;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            Row[i]=(Row[i]<a[i][j])?Row[i]:a[i][j];
        }
    }
    for(j=1;j<=m;++j){
        for(i=1;i<=n;++i){
            Line[j]=(Line[j]>a[i][j])?Line[j]:a[i][j];
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            if(a[i][j]==Line[j]&&a[i][j]==Row[i]){
                printf("%d ",a[i][j]);
            }
        }
    }
    return 0;
}
