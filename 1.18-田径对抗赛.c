#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char p,g,s;
int score,i;
int vis[5];
int S[6][3];
int main(){
	while(scanf("%c ",&p)!=EOF){
		scanf("%c %c %d\n",&g,&s,&score);
		vis[s-'A']=1;
		if(g=='M'){
			S[s-'A'][0]+=score;
		}
		else S[s-'A'][1]+=score;
	}
	for(i=0;i<5;++i){
		if(S[i][0]+S[i][1]==0)continue;
		if(S[i][0]!=0){
			printf("%c M %d\n",i+'A',S[i][0]);
		}
		if(S[i][1]!=0){
			printf("%c F %d\n",i+'A',S[i][1]);
		}
		printf("%c %d\n",i+'A',S[i][0]+S[i][1]);
	}
	return 0;
} 
