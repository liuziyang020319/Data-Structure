#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tot[101];
int a[101][10001];
void ins(int k,int x){
    int i=0,j;
    if(tot[k]==0){
        a[k][++tot[k]]=x;
        return;
    }
    int mod=(1<<(1+k));
    int Goal;
    if(x%mod == (1<<k)){
        Goal=x-(1<<k);
    }
    else{
        Goal=x+(1<<k);
    }
    int flag=0;
    for(i=1;i<=tot[k];i++){
        if(a[k][i]==Goal){
            int knew=k+1;
            int xnew=Goal<x?Goal:x;
            for(j=i;j<=tot[k];j++){
                a[k][j]=a[k][j+1];
            }
            tot[k]--;
            ins(knew,xnew);
            return;
        }
    }
    for(i=1;i<=tot[k];i++){
        if(a[k][i]>x){
            tot[k]++;
            for(j=tot[k];j>i;j--){
                a[k][j]=a[k][j-1];
            }
            a[k][i]=x;
            return;
        }       
    }
    tot[k]++;
    a[k][tot[k]]=x;
    return;
}
int main(){
    char ch=getchar();
    while(1){
        int k=0;
        while(ch<'0'||ch>'9'){
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            k=k*10+ch-'0';
            ch=getchar();
        }
        
        int x=0;
        while(ch!='\n'&&ch!=EOF){
            // tot[k]++;
            while(ch<'0'||ch>'9'){
                ch=getchar();
            } 
            x=0;
            while(ch>='0'&&ch<='9'){
                x=x*10+ch-'0';
                ch=getchar();
            }      
            ins(k,x);
            // a[k][tot[k]]=x;       
            // printf("%d %d\n",k,x);          
        }
        // int i,j;
        // for(i=1;i<=tot[k];++i){
        //     for(j=1;j<=tot[k]-i;++j){
        //         if(a[k][j]>a[k][j+1]){
        //             int temp=a[k][j];
        //             a[k][j]=a[k][j+1];
        //             a[k][j+1]=temp;
        //         }
        //     }
        // }
        ch=getchar();
        if(ch=='\n'||ch==EOF)break;
    }
    if(ch=='\n'){
        ch=getchar();
    }
    while(ch!=EOF){
        int k=0;
        while(ch<'0'||ch>'9'){
            ch=getchar();
        }
        while(ch>='0'&&ch<='9'){
            k=k*10+ch-'0';
            ch=getchar();
        }
        int x=0;
        while(ch<'0'||ch>'9'){
            ch=getchar();
        } 
        x=0;
        while(ch>='0'&&ch<='9'){
            x=x*10+ch-'0';
            ch=getchar();
        }                     
        ins(k,x);        
        if(ch==EOF)break;
        ch=getchar();
        if(ch==EOF)break;
    }
    int i,flag=0;
    for(i=0;i<=100;++i){
        if(tot[i]!=0){
            int j;
            if(flag)printf("\n");
            printf("%d ",i);
            for(j=1;j<=tot[i];++j){
                printf("%d",a[i][j]);
                if(j!=tot[i])printf(" ");
            }
            flag=1;
        }
    }
    return 0;
}