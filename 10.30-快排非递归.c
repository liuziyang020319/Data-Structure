#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Node{
    int l,r;
}* PT;
PT S[100010];
int a[100010];
int top=0;
PT Top(){
    PT ret=S[top];
    top--;
    return ret;
}
void Push(int l,int r){
    PT now=malloc(sizeof(struct Node));
    now->l=l;
    now->r=r;
    S[++top]=now;
}
int Empty(){
    return top==0;
}
int n;
void Quick_Sort(){
    Push(1,n);
    while(!Empty()){
    	
        PT now=Top();
        int l=now->l;
        int r=now->r;
		
        if(l>=r)continue;
        int flag=l+rand()%(r-l+1);
        int val=a[flag];
        while(l<=r){
            while(a[l]<val)l++;
            while(a[r]>val)r--;
            if(l<=r){
	            int tmp=a[l];
	            a[l]=a[r];
	            a[r]=tmp;   
				l++;
				r--;         	
			}	
		}
        Push(now->l,r);
        Push(l,now->r);
    }
}
int x;
int main(){
    while(scanf("%d",&x)!=EOF){
        a[++n]=x;
    }
    Quick_Sort();
    int i;
    for(i=1;i<=n;++i){
        printf("%d",a[i]);
        if(i!=n)printf(" ");
    }
    return 0;
}
