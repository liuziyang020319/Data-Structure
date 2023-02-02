#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[100100];
int tmp[100100];
int tmpL[100100];
int tmpR[100100];
void Merge_Sort(int a[],int l,int r){
    if(l>=r)return;
    int mid=(l+r)>>1;
    Merge_Sort(a,l,mid);
    Merge_Sort(a,mid+1,r);
    int i;
    tmpL[0]=tmpR[0]=0;
    for(i=l;i<=mid;++i){
        tmpL[++tmpL[0]]=a[i];
    }
    for(i=mid+1;i<=r;++i){
        tmpR[++tmpR[0]]=a[i];
    }
    int cntL=1,cntR=1;
    for(i=l;i<=r;++i){
        if(cntL<=tmpL[0]&&cntR<=tmpR[0]){
            if(tmpL[cntL]<tmpR[cntR]){
                a[i]=tmpL[cntL];
                cntL++;
            }
            else{
                a[i]=tmpR[cntR];
                cntR++;
            }
        }
        else{
            if(cntL>tmpL[0]&&cntR<=tmpR[0]){
                a[i]=tmpR[cntR];
                cntR++;
            }
            else{
                if(cntR>tmpR[0]&&cntL<=tmpL[0]){
                    a[i]=tmpL[cntL];
                    cntL++;
                }
            }
        }
    }
}
int n;

int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    Merge_Sort(a,1,n);
    for(i=1;i<=n;++i){
        printf("%d",a[i]);
        if(i!=n)printf(" ");
    }
    return 0;
}