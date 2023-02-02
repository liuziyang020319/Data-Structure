#include<stdio.h>
int a[100010],n;
void Modify(int pos,int n){
    int i,fa=pos;
    for(i=pos*3-1;i<=n;fa=i,i=i*3-1){
        int x=i;
        int y=i+1;
        int z=i+2;
        if(x<=n&&a[x]>a[i])i=x;
        if(y<=n&&a[y]>a[i])i=y;
        if(z<=n&&a[z]>a[i])i=z;
        if(a[fa]<a[i]){
            int tmp=a[fa];
            a[fa]=a[i];
            a[i]=tmp;
        }
        else break;
    }
}
void Heap_Sort(int n){
    int i;
    for(i=n;i>0;--i){
        Modify(i,n);
    }
    for(i=n;i>0;--i){
        int tmp=a[1];
        a[1]=a[i];
        a[i]=tmp;
        Modify(1,i-1);
    }
    for(i=1;i<=n;++i){
        printf("%d",a[i]);
        if(i!=n)printf(" ");
    }
}
int x;
int main(){
    while(scanf("%d",&x)!=EOF){
        a[++n]=x;
    }
    Heap_Sort(n);
    return 0;
}