#include<stdio.h>
typedef long long LL;
LL MAXINT=(1LL<<32)-1;
int a[21],n,arrsize;
LL Cal(int i){
	int j;
	LL ret=1;
	for(j=1;j<=i;++j){
		ret=ret*2*j;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&arrsize);
	if(n>arrsize){
		printf("-1");
		return 0;
	} 
	int i;
	for(i=0;i<n;++i){
		LL x=Cal(i);
		if(x>MAXINT){
			printf("-1");
			return 0;	
		}
		a[i]=(int)x;
	}
	for(i=0;i<n;++i){
		printf("%d ",a[i]);
	}
	return 0;
}
