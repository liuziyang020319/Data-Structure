//AVL Tree Pointer Version
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct AVLNode{
    int data,height,size,bf,freq;
    struct AVLNode * ls;
    struct AVLNode * rs;
} * PT;
void Clr(PT P){
    P->data=P->height=P->size=P->bf=P->freq=0;
    P->ls=P->rs=NULL;
}
int GetSize(PT P){
    if(P==NULL)return 0;
    return P->size;
}
int GetHeight(PT P){
    if(P==NULL)return 0;
    return P->height;
}
void Update(PT P){
    P->size=GetSize(P->ls)+GetSize(P->rs)+P->freq;
    P->height=max(GetHeight(P->ls),GetHeight(P->rs))+1;
    P->bf=GetHeight(P->ls)-GetHeight(P->rs);
}
void LL(PT &P){
    PT lson=P->ls;
    P->ls=lson->rs;
    lson->rs=P;
    Update(P);
    Update(lson);
    P=lson;
}
void RR(PT &P){
    PT rson=P->rs;
    P->rs=rson->ls;
    rson->ls=P;
    Update(P);
    Update(rson);
    P=rson;
}
void LR(PT &P){
    PT lson=P->ls;
    PT lson_rson=lson->rs;
    lson->rs=lson_rson->ls;
    P->ls=lson_rson->rs;
    lson_rson->ls=lson;
    lson_rson->rs=P;
    Update(lson);Update(P);//L R
    Update(lson_rson);//fa
    P=lson_rson;
}
void RL(PT &P){
    PT rson=P->rs;
    PT rson_lson=rson->ls;
    rson->ls=rson_lson->rs;
    P->rs=rson_lson->ls;
    rson_lson->ls=P;
    rson_lson->rs=rson;
    Update(P);Update(rson);//R L
    Update(rson_lson);//fa
    P=rson_lson;
}
void Insert_DFS(PT &P,int x){
    if(P==NULL){
        P=(PT)malloc(sizeof(struct AVLNode));
        Clr(P);
        P->data=x;
        P->size=P->height=P->freq=1;
        return;
    }
    if(P->data==x){
        P->freq=P->freq+1;
        Update(P);
        return;
    }
    if(P->data>x){
        Insert_DFS(P->ls,x);
        Update(P);
        if(P->bf==2){
            if(x<P->ls->data)LL(P);
            else LR(P);
        }
    }
    else{
        Insert_DFS(P->rs,x);
        Update(P);
        if(P->bf==-2){
            if(x>P->rs->data)RR(P);
            else RL(P);
        }
    }
}
inline void Erase(PT &P,int x){
    if(P==NULL)return;
    if(P->data==x){
        if(P->freq>1){
            P->freq=P->freq-1;
            Update(P);
            return;
        }
        if(P->ls!=NULL&&P->rs!=NULL){
        	
            PT suc=P->rs;
            while(suc->ls!=NULL)suc=suc->ls;
            P->data=suc->data;
            P->freq=suc->freq;
            suc->freq=1;//for delete
            Erase(P->rs,suc->data);
            Update(P);
            if(P->bf==2){
                if(P->ls->bf>=0)LL(P);
                else LR(P);
            }
            return;
        }
        else{
            if(P->ls!=NULL){
                PT Q=P;
                P=P->ls;
                free(Q);
                Update(P);
                return;
            }
            if(P->rs!=NULL){
                PT Q=P;
                P=P->rs;
                free(Q);
                Update(P);
                return;
            }
            PT Q=P;
            P=NULL;
            free(Q);
            return;
        }
    }
    if(P->data>x){
        Erase(P->ls,x);
        Update(P);
        if(P->bf==-2){
            if(P->rs->bf<=0)RR(P);
            else RL(P);
        }
        return;
    }
    if(P->data<x){
        Erase(P->rs,x);
        Update(P);
        if(P->bf==2){
            if(P->ls->bf>=0)LL(P);
            else LR(P);
        }
        return;
    }
}
int GETKth(PT P,int rank){
    if(GetSize(P->ls)>=rank)return GETKth(P->ls,rank);
    if(GetSize(P->ls)+P->freq>=rank)return P->data;
    return GETKth(P->rs,rank-GetSize(P->ls)-P->freq);
}
int GETRank(PT P,int x){
    if(P->data==x)return GetSize(P->ls)+1;
    if(P->data>x )return GETRank(P->ls,x);
    return GETRank(P->rs,x)+P->freq+GetSize(P->ls);
}
int GETPre(PT P,int x){
    PT ans=(PT)malloc(sizeof(struct AVLNode));
    Clr(ans);
    ans->data=-2e9;
    while(P!=NULL){
        if(P->data==x){
            if(P->ls!=NULL){
                P=P->ls;
                while(P->rs!=NULL)P=P->rs;
                ans=P;
            }
            break;
        }
        if(P->data<x&&P->data>ans->data)ans=P;
        P=P->data<x?P->rs:P->ls;
    }
    return ans->data;
}
int GETSuc(PT P,int x){
    PT ans=(PT)malloc(sizeof(struct AVLNode));
    Clr(ans);
    ans->data=2e9;
    while(P!=NULL){
        if(P->data==x){
            if(P->rs!=NULL){
                P=P->rs;
                while(P->ls!=NULL)P=P->ls;
                ans=P;
            }
            break;
        }
        if(P->data>x&&P->data<ans->data)ans=P;
        P=P->data<x?P->rs:P->ls;
    }
    return ans->data;
}
void Print(PT P){
	if(P->ls!=NULL)Print(P->ls);
    int i;
    for(i=1;i<=P->freq;++i)
        printf("%d ",P->data);
    if(P->rs!=NULL)Print(P->rs);
} 
PT root;
int n,x,opt;
int main(){
//	freopen("P3369.txt","r",stdin);
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d%d",&opt,&x);
        switch(opt){
            case 1: Insert_DFS(root,x);break;
            case 2: Erase(root,x);break;
            case 3: printf("%d\n",GETRank(root,x));break;
            case 4: printf("%d\n",GETKth(root,x));break;
            case 5: printf("%d\n",GETPre(root,x));break;
            case 6: printf("%d\n",GETSuc(root,x));break;
        }
    }
    return 0;
}
