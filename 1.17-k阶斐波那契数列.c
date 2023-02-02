#include<stdio.h>
/*int a[100][100],b[100][100],c[100][100],k,m;
void copy(int (*a)[100],int (*b)[100]);
void operate(int (*a)[100],int (*b)[100]){
    int i,j,l;
    int c[100][100];
    for(i=1;i<=k;++i){
        for(j=1;j<=k;++j){
            c[i][j]=0;
        }
    }
    for(i=1;i<=k;++i){
        for(j=1;j<=k;++j){
            for(l=1;l<=k;++l){
                c[i][j]+=a[i][l]*b[l][j];
            }
        }
    }
    copy(a,c);
}
void init(int (*a)[100]){
    int i,j;
    for(i=1;i<=k;++i){
        for(j=1;j<=k;++j){
            a[i][j]=0;
        }
    }
}
void copy(int (*a)[100],int (*b)[100]){
    int i,j;
    for(i=1;i<=k;++i){
        for(j=1;j<=k;++j){
            a[i][j]=b[i][j];
        }
    }
}
void power(int (*a)[100],int k){
    int tmp[100][100],i;
    init(tmp);
    for(i=1;i<=k;++i){
        tmp[i][i]=1;
    }
    while(k){
        if(k&1){
            operate(tmp,a);
        }
        operate(a,a);
        k>>=1;
    }
    copy(a,tmp);
}
int main(){
    scanf("%d%d",&k,&m);
    if(m<k){
        printf("0");
        return 0;
    }
    else{
        if(k==m){
            printf("1");
            return 0;
        }
    }
    init(a);
    a[1][k]=1;
    init(b);
    int i;
    for(i=1;i<=k-1;++i){
        b[i+1][i]=1;
    }
    for(i=1;i<=k;++i){
        b[i][k]=1;
    }
    power(b,m-k+1);
    operate(a,b);
    printf("%d",a[1][k]);
    return 0;
}*/
int a[100000]={},m,i,j,k;
int main(){
	scanf("%d%d",&k,&m);
	a[k-1]=1;
	for(i=k;i<=m;++i){
		for(j=i-k;j<i;++j){
			a[i]+=a[j]; 
		}
	}
	printf("%d",a[m]);
}
