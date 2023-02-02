#include<string.h>
#include<stdio.h>
char A[1000],B[1000];
int main(){
	scanf("%s%s",A,B);
	int cmp=strcmp(A,B);
	if(cmp<0)printf("1");
	if(cmp==0)printf("0");
	if(cmp>0)printf("2");
	return 0;
}  
