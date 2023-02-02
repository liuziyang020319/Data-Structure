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
struct SplayTree{
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
}T1,T2;

void DFS_INS(SPLAYNode *now, SplayTree * T2){
    if(now->ch[0]!=NULL)DFS_INS(now->ch[0],T2);
    T2->Ins(now->key);
    if(now->ch[1]!=NULL)DFS_INS(now->ch[1],T2);
}

SplayTree Merge(SplayTree T1,SplayTree T2){
    if(T1.root->siz>T2.root->siz){
        swap(T1,T2);
    }
    // puts("in");
    printf("%d\n",T2.root->siz);
    DFS_INS(T1.root,&T2);
    // puts("out");
    printf("%d\n",T2.root->siz);
    return T2;
}

int n,opt,x;

void writeTreeNode(SPLAYNode *node, FILE *fp) {
    if(!node) return;
    if (node->ch[0]) {
        fprintf(fp, "\t%d -> %d;\n", node->key, node->ch[0]->key);
        if (node->ch[1] == NULL) {
            fprintf(fp, "\t%d -> null%d[weight=100, style=invis];null%d[style=invis];\n", node->key, node->key,
                    node->key);
        }
        writeTreeNode(node->ch[0], fp);
    }

    if (node->ch[1]) {
        if (node->ch[0] == NULL) {
            fprintf(fp, "\t%d -> null%d[weight=100, style=invis];null%d[style=invis];\n", node->key, node->key,
                    node->key);
        }
        fprintf(fp, "\t%d -> %d;\n", node->key, node->ch[1]->key);
        writeTreeNode(node->ch[1], fp);
    }

}

void showTree(SPLAYNode *tree, FILE *pFILE) {
    fprintf(pFILE, "digraph BSTree{\n");
    writeTreeNode(tree, pFILE);
    fprintf(pFILE, "}\n");
}

int main(){
	// freopen("Merge.txt","r",stdin);
    printf("请在两行分别输入两个平衡树的数据：\n");
    T1.root=T2.root=NULL;
    int i;
    for(i=1;i<=5;++i){
        scanf("%d",&x);
        T1.Ins(x);
    }
    for(i=1;i<=10;++i){
        scanf("%d",&x);
        T2.Ins(x);
    }
    system("rm ./tree1.dot");
    FILE *fp1 = fopen("./tree1.dot", "w");
    showTree(T1.root,fp1);
    fclose(fp1);

    system("dot -Tpng ./tree1.dot -o ./tree1.png");
    system("tree1.png");
    // system("pause");
    // getchar();

    system("rm ./tree2.dot");
    FILE *fp2 = fopen("./tree2.dot", "w");
    showTree(T2.root,fp2);
    fclose(fp2);

    system("dot -Tpng ./tree2.dot -o ./tree2.png");
    system("tree2.png");
    system("pause");
    getchar();

    T2 = Merge(T1,T2);

    system("rm ./tree3.dot");
    FILE *fp3 = fopen("./tree3.dot", "w");
    showTree(T2.root,fp3);
    fclose(fp3);

    system("dot -Tpng ./tree3.dot -o ./tree3.png");
    system("tree3.png");
    system("pause");    

    printf("请输入分裂的键值:\n");
    int key;
    scanf("%d",&key);
    T2.Ins(key);
    // printf("%d\n",T2.root->cnt);
    T2.Del(key);
    // printf("%d\n",T2.root->key);
    T1.root=T2.root->ch[1];
    T2.root->ch[1]=NULL;
    T2.Update(T2.root);
    system("rm ./tree1.dot");
    FILE *fp4 = fopen("./tree1.dot", "w");
    showTree(T1.root,fp4);
    fclose(fp4);

    system("dot -Tpng ./tree1.dot -o ./tree1.png");
    system("tree1.png");
    // system("pause");
    // getchar();

    system("rm ./tree2.dot");
    FILE *fp5 = fopen("./tree2.dot", "w");
    showTree(T2.root,fp5);
    fclose(fp5);

    system("dot -Tpng ./tree2.dot -o ./tree2.png");
    system("tree2.png");
    // system("pause");
    // getchar();
    return 0;
}
