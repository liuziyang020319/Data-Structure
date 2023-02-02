//SPLAY Pointer Version
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef struct SPLAYNode{
    int key;
    int siz;
    int cnt;
    struct SPLAYNode * ch[2];
    struct SPLAYNode * fa;
}* PT;
PT root;
void Clr(PT P){
    P->ch[0]=P->ch[1]=NULL;
    P->fa=NULL;
    P->siz=P->cnt=P->key=0;
}
int GetSon(PT P){//RSON
    if(P->fa==NULL)return 0;
    return P->fa->ch[1]==P;
}
void Update(PT P){
    if(P!=NULL){
        P->siz=P->cnt;
        if(P->ch[0]!=NULL)P->siz+=P->ch[0]->siz;
        if(P->ch[1]!=NULL)P->siz+=P->ch[1]->siz;
    }
}
void Rotate(PT P){
    PT fat=P->fa;
    PT grandfat=fat->fa;
    int jud=GetSon(P);
    fat->ch[jud]=P->ch[jud^1];
    if(P->ch[jud^1]!=NULL)P->ch[jud^1]->fa=fat;
    P->ch[jud^1]=fat;
    fat->fa=P;
    P->fa=grandfat;
    if(grandfat!=NULL){
        grandfat->ch[grandfat->ch[1]==fat]=P;
    }
    Update(fat);
    Update(P);
}
void Splay(PT P){
    PT fat;
    for(;(fat=P->fa)!=NULL;Rotate(P)){
        if(fat->fa!=NULL){
            if(GetSon(P)==GetSon(fat))
                Rotate(fat);
            else
                Rotate(P);
        }
    }
    root=P;
}
void Ins(int x){
    if(root==NULL){
        PT P;
        P=(PT)malloc(sizeof(struct SPLAYNode));
        P->ch[0]=P->ch[1]=NULL;
        P->fa=NULL;
        P->key=x;
        P->cnt=1;
        P->siz=1;
        root=P;
        return;
    }
    PT now=root;
    PT fat=NULL;
    while(1){
        if(now->key==x){
            now->cnt=now->cnt+1;
            Update(now);
            Update(fat);
            Splay(now);
            break;
        }
        fat=now;
        now=now->ch[now->key<x];
        if(now==NULL){
            now=(PT)malloc(sizeof(struct SPLAYNode));
            now->ch[0]=now->ch[1]=NULL;
            now->fa=fat;
            now->siz=now->cnt=1;
            now->key=x;
            if(fat!=NULL)fat->ch[fat->key<x]=now;
            Update(fat);
            Splay(now);
            break;
        }
    }
}
int GetRank(int x){
    int ans=0;
    PT now=root;
    while(1){
        if(x<now->key){
            now=now->ch[0];
        }
        else{
            if(now->ch[0]!=NULL){
                ans+=now->ch[0]->siz;
            }
            if(x==now->key){
                Splay(now);
                return ans+1;
            }
            ans+=now->cnt;
            now=now->ch[1];
        }
    }
}
int GetPos(int x){
    PT now=root;
    while(1){
        int temp=0;
        if(now->ch[0]!=NULL&&x<=now->ch[0]->siz){
            now=now->ch[0];
        }
        else{
            if(now->ch[0])
                temp=now->ch[0]->siz;
            temp+=now->cnt;
            if(x<=temp)
                return now->key;
            x-=temp;
            now=now->ch[1];
        }
    }
}
PT pre(){
	PT now=root->ch[0];
	while(now->ch[1]!=NULL)
		now=now->ch[1];
	return now;
}
PT nxt(){
	PT now=root->ch[1];
	while(now->ch[0]!=NULL)
		now=now->ch[0];
	return now;
}
void Del(int x){
    int whatever=GetRank(x);
    if(root->cnt>1){
        root->cnt=root->cnt-1;
        Update(root);
        return;
    }
    if(root->ch[0]==NULL&&root->ch[1]==NULL){
        free(root);
        root=NULL;
        return;
    }
    if(root->ch[0]==NULL){
        PT oldroot=root;
        root=root->ch[1];
        root->fa=NULL;
        free(oldroot);
        return;
    }
    else{
        if(root->ch[1]==NULL){
            PT oldroot=root;
            root=root->ch[0];
            root->fa=NULL;
            free(oldroot);
            return;
        }
    }
    PT leftbig=pre();
    PT oldroot=root;
    Splay(leftbig);
    oldroot->ch[1]->fa=root;
    root->ch[1]=oldroot->ch[1];
    free(oldroot);
    Update(root);
    return;
}
int n,opt,x;

void writeTreeNode(SPLAYNode *node, FILE *fp) {
    if(!node) return;
    if (node->ch[1]) {
        fprintf(fp, "\t%d -> %d;\n", node->key, node->ch[1]->key);
        if (node->ch[0] == nullptr) {
            fprintf(fp, "\t%d -> null%d[weight=100, style=invis];null%d[style=invis];\n", node->key, node->key,
                    node->key);
        }
        writeTreeNode(node->ch[1], fp);
    }
    if (node->ch[0]) {
        fprintf(fp, "\t%d -> %d;\n", node->key, node->ch[0]->key);
        if (node->ch[1] == nullptr) {
            fprintf(fp, "\t%d -> null%d[weight=100, style=invis];null%d[style=invis];\n", node->key, node->key,
                    node->key);
        }
        writeTreeNode(node->ch[0], fp);
    }
}

void showTree(SPLAYNode *tree, FILE *pFILE) {
    fprintf(pFILE, "digraph BSTree{\n");
    writeTreeNode(tree, pFILE);
    fprintf(pFILE, "}\n");
}

int main(){
	freopen("P3369.txt","r",stdin);
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d%d",&opt,&x);
        switch(opt){
            case 1: Ins(x);break;
            case 2: Del(x);break;
            case 3: printf("%d\n",GetRank(x));break;
            case 4: printf("%d\n",GetPos(x));break;
            case 5: Ins(x);printf("%d\n",pre()->key);Del(x);break;
            case 6: Ins(x);printf("%d\n",nxt()->key);Del(x);break;
        }

        
        char filename[100];
        sprintf(filename,"./tree%d.dot",i);
        FILE *fp = fopen(filename, "w");
        showTree(root,fp);

// not work, dont know why
//        char cmdname[100];
//        sprintf(cmdname,"dot -Tpng tree%d.dot -o tree%d.png > out.txt 2>&1",i,i);
//        printf("%s\n",cmdname);
//        system(cmdname);
//
//        system("pwd");
    }
    return 0;
}
