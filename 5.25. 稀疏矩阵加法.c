#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{
    int x,y,sum;
}Asum[1000+10],Bsum[1000+10],Csum[1000+10];
int n,m;
int cntA,cntB,cntC;
int A[1000+10][1000+10];
int B[1000+10][1000+10],C[1000+10][1000+10];
int main(){
    scanf("%d %d",&n,&m);
    int x;
    char c;
    c=getchar();
    while((c=getchar())!='\n'){
        int flag=1;
        x=0;
        while((c<'0'||c>'9')&&c!='\n'){
            if(c=='-')flag=-1;
            c=getchar();
        }
        if(c=='\n')break;
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        x=x*flag;
        Asum[++cntA].sum=x;
        if(c=='\n')break;
    }
    int i,j,tot;

    for(tot=0,i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&A[i][j]);
            if(A[i][j])A[i][j]*=Asum[++tot].sum;
        }
    }    
    c=getchar();
    while((c=getchar())!='\n'){
        int flag=1;
        x=0;
        while((c<'0'||c>'9')&&c!='\n'){
            if(c=='-')flag=-1;
            c=getchar();
        }
        if(c=='\n')break;
        while(c>='0'&&c<='9'){
            x=x*10+c-'0';
            c=getchar();
        }
        x=x*flag;
        Bsum[++cntB].sum=x;
        if(c=='\n')break;
    } 
    for(tot=0,i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            scanf("%d",&B[i][j]);
            if(B[i][j])B[i][j]*=Bsum[++tot].sum;
        }
    }
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            C[i][j]=A[i][j]+B[i][j];
            if(C[i][j]){
            	++cntC;
            	Csum[cntC].sum=C[i][j];
            }
		}
    }
    for(i=1;i<cntC;++i){
    	printf("%d ",Csum[i].sum);
    }
    if(cntC)
    	printf("%d\n",Csum[cntC].sum);
    else puts("");
	for(i=1;i<=n;++i){
        for(j=1;j<m;++j){
            if(C[i][j])printf("1 ");
            else printf("0 ");
		}
		if(C[i][m])printf("1\n");
		else printf("0\n");
    }    
    return 0;
}
