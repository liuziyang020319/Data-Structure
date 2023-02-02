#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[500001];
int top=0;
int flagleft,flagstring,cnt;
char c;
int main(){
    while((c=getchar())!=EOF){
        if(c=='"'&&!flagleft)flagstring^=1;
        if(!flagstring){
        	if(flagleft)cnt++;
            if(c=='*'&&top>=0&&stack[top]=='/'){
                if(flagleft){
					stack[++top]=c;  
                }
                else{
                    flagleft=top;
					cnt=2;
                    stack[++top]=c;                   
                }
            }
            else{
                if(c=='/'&&flagleft&&top>=0&&cnt>=4&&stack[top]=='*'){
                    top--;
                    while(top>=flagleft){
                        --top;
                    }
                    flagleft=0;
                    cnt=0;
                }
                else{
                    stack[++top]=c;
                }
            }
        }
        else{
            stack[++top]=c;
        }
    }
    int i;
    for(i=1;i<=top;++i){
    	printf("%c",stack[i]);
    }
    return 0;
}
