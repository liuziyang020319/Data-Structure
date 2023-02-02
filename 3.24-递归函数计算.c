#include<stdio.h>
int G(int m,int n){
	if(m==0)return 0;
	return G(m-1,2*n)+n;
}
int n,m;
int main(){
	scanf("%d,%d",&m,&n);
	printf("%d",G(m,n));
	return 0;
}
