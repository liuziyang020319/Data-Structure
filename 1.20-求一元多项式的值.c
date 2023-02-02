#include<stdio.h>
int Quick_Power(int x,int k){
	int ret=1;
	while(k){
		if(k&1){
			ret=ret*x;
		}
		x=x*x;
		k>>=1;
	}
	return ret;
}
int x0,n,i,sum=0;
int main(){
	scanf("%d%d",&x0,&n);
	for(i=0;i<=n;++i){
		int a;
		scanf("%d",&a);
		sum+=a*Quick_Power(x0,i);
	}
	printf("%d",sum);
	return 0;
}
