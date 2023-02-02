#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[1001];
char b[1001];
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
int flag=0,cnt=0;
int main(){
    char * now=a;
    while((c=getchar())!='@'){
        if(c=='&'){
            if(flag==1){
                printf("0");
                return 0;
            }
            else{
                flag=1;
                now[cnt]='\0';
                now=b;
                cnt=0;
            }
        }
        else now[cnt++]=c;
    }
    if(flag==0){
        printf("0");
        return 0;
    }
//    printf("%s %s\n",a,b);
    now[cnt++]='\0';
    reverse(b);
    if(strcmp(a,b)==0){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}
