#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[1001];
void reverse(char *a){
    int len=strlen(a),i;
    char c[1001];
    for(i=0;i<len;++i){
        c[i]=a[len-i-1];
    }
    for(i=0;i<len;++i){
        a[i]=c[i];
    }
}
char c;
int cnt=0;
int main(){ 
	while((c=getchar())!=EOF&&c!='\n'){
		a[cnt++]=c;
	}
	a[cnt]='\0';
    reverse(a);
    printf("%s",a);
    return 0;
}
