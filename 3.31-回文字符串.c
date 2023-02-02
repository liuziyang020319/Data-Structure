#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void judge(char s[]){
	int len=strlen(s),i;
	for(i=0;i<len;++i){
		if(s[i]!=s[len-1-i]){
			printf("0\n");
			return;	
		} 
	}
	printf("1\n");
	return;
}
char c;
char s[10000+10];
int main(){
	while((c=getchar())!=EOF){
		int len=0;
		memset(s,0,sizeof(s));
		for(;;c=getchar()){
			if(c=='@'){
				s[len]='\0';
				c=getchar();
				judge(s);
				break;
			}
			else{
				s[len++]=c;
			}
		}
	}
	return 0;
}
