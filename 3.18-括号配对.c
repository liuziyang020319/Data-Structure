#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10000];
int main(){
	while(scanf("%s",s)!=EOF){
		int cnt=0,i,GG=0;
		int len=strlen(s);
		for(i=0;i<len;++i){
			if(s[i]=='(')cnt++;
			if(s[i]==')'){
				if(cnt)cnt--;
				else GG=1;
			}
		}
		if(cnt)GG=1;
		if(GG)printf("0\n");
		else printf("1\n");
	}
	return 0;
}
