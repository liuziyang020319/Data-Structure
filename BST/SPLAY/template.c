#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int ch[N][2]={0};
int fa[N]={0};
int key[N]={0};
int siz[N]={0};
int cnt[N]={0};
int tot=0;
int root=0;
/*f[i]表示i的父结点，
ch[i][0]表示i的左儿子，
ch[i][1]表示i的右儿子，
key[i]表示i的关键字（即结点i代表的那个数字）即离散化，
cnt[i]表示i结点的关键字出现的次数（相当于权值），
siz[i]表示包括i的这个子树的大小；
tot为整棵树的大小，
root为整棵树的根。*/
/*二叉排序树，左儿子小，右儿子大*/ 
inline void clear(int x){/*将当前点的各项值都清0（用于删除之后）*/
	ch[x][0]=ch[x][1]=0;
	fa[x]=0;
	siz[x]=0;
	cnt[x]=0;
	key[x]=0;
}
inline int getson(int x){
	return ch[fa[x]][1]==x;
}
inline void update(int x){
	if(x){
//		cout<<"updatenow "<<x<<endl;
		siz[x]=cnt[x];
		if(ch[x][0]){
			siz[x]+=siz[ch[x][0]];
		}
		if(ch[x][1]){
			siz[x]+=siz[ch[x][1]];
		}
	} 
}//更新子树值 
inline void rotate(int x){
	int fat=fa[x];
	int grandfat=fa[fat];
	int jud=getson(x);//判断左旋右旋 
	ch[fat][jud]=ch[x][jud^1];
	fa[ch[x][jud^1]]=fat;
	ch[x][jud^1]=fat;
	fa[fat]=x;
	fa[x]=grandfat;
	if(grandfat){
		ch[grandfat][ch[grandfat][1]==fat]=x;//如果有祖父，即不是根结点，把左/右赋值为x. 
	}
	update(fat);
	update(x);
}
inline void splay(int x){
	for(int fat;(fat=fa[x])/*root以上=0,所以当为root，退出*/;rotate(x)){
		if(fa[fat]){
			if(getson(x)==getson(fat))
				rotate(fat);
			else
				rotate(x); 
		}
	} 
	root=x;
}
inline void ins(int x){
	if(root==0){
		tot++;
		ch[tot][0]=ch[tot][1]=0;
		fa[tot]=0;
		key[tot]=x;
		cnt[tot]=1;
		siz[tot]=1;
		root=tot;
		return;
	}
	int now=root;
	int fat=0;
	while(1){
		if(key[now]==x){//如果当前点离散值等于插入值，权值增加。 
			cnt[now]++;
			update(now);//先做当前点更新，在做父亲点的。
			update(fat);
			splay(now);
			break; 
		}
		fat=now;
		now=ch[now][key[now]<x];//左儿子为0，右儿子为1
		if(now==0){
			tot++;
			ch[tot][0]=ch[tot][1]=0;
			fa[tot]=fat;
			siz[tot]=cnt[tot]=1;
			ch[fat][key[fat]<x]=tot;
			key[tot]=x;
			update(fat);
			splay(tot);
			break;
		} 
	} 
}
/*如果x比当前结点小，即应该向左子树寻找，ans不用改变（设想一下，走到整棵树的最左端最底端排名不就是1吗）。
如果x比当前结点大，即应该向右子树寻找，ans需要加上左子树的大小以及根的大小（这里的大小指的是权值）。*/ 
inline int getrank(int x){
	int ans=0;
	int now=root;
	while(1){
//		cout<<now<<endl;
		if(x<key[now]){
			now=ch[now][0];//如果比当前数小，走左儿子。 
		}
		else{
			if(ch[now][0]){
				ans+=siz[ch[now][0]];
			}
			if(x==key[now]){
				splay(now);//为什么要 Splay 是为了保证复杂度 
				return ans+1;
			}
			ans+=cnt[now];
			now=ch[now][1];
		}
	} 
}
inline int getpos(int x){
	int now=root;
	while(1){
		int temp=0;
		if(ch[now][0]&&x<=siz[ch[now][0]]){
			now=ch[now][0];
		}
		else{
			if(ch[now][0]){
				temp=siz[ch[now][0]];
			}
			temp+=cnt[now];
			if(x<=temp)
				return key[now];//为什么不取等，是因为有重复值 
			x-=temp;
			now=ch[now][1];
		}
	}
}
//前驱 在我们做insert操作之后做了一遍splay。这就意味着我们把x已经splay到根了。求x的前驱其实就是求x的左子树的最右边的一个结点，后继是求x的右子树的左边一个结点
inline int pre(){
	int now=ch[root][0];
//	cout<<now<<endl;
	while(ch[now][1])
		now=ch[now][1];
	return now;
}
//后继 
inline int nxt(){
	int now=ch[root][1];
	while(ch[now][0])
		now=ch[now][0];
	return now;
}
/* 
	step 1：随便find一下x。目的是：将x旋转到根。
	step 2：那么现在x就是根了。如果cnt[root]>1，即不只有一个x的话，直接-1返回。
	step 3：如果root并没有孩子，就说名树上只有一个x而已，直接clear返回。
	step 4：如果root只有左儿子或者右儿子，那么直接clear root，然后把唯一的儿子当作根就可以了（f赋0，root赋为唯一的儿子）
剩下的就是它有两个儿子的情况。
	step 5：我们找到新根，也就是x的前驱（x左子树最大的一个点），将它旋转到根。然后将原来x的右子树接到新根的右子树上（注意这个操作需要改变父子关系）。这实际上就把x删除了。不要忘了update新根。
*/
void del(int x){
	int whatever=getrank(x);
	if(cnt[root]>1){
		cnt[root]--;
		return;
	}
	if(!ch[root][0]&&!ch[root][1]){
		clear(root);
		root=0;
		return;
	}
	if(!ch[root][0]){
		int oldroot=root;
		root=ch[root][1];
		fa[root]=0;
		clear(oldroot);
		return;
	}
	else{if(!ch[root][1]){
		int oldroot=root;
		 root=ch[root][0];
		 fa[root]=0;
		 clear(oldroot);
		 return;
		}	 
	}
	int leftbig=pre();
	int oldroot=root;
	splay(leftbig);
	fa[ch[oldroot][1]]=root;
	ch[root][1]=ch[oldroot][1];
	clear(oldroot);
	update(root);
	return;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		int opt;
		scanf("%d%d",&opt,&x);
		int ans=0;
		switch(opt){
			case 1: ins(x);break;
			case 2: del(x);break;
			case 3: ans=getrank(x);printf("%d\n",ans);break;
			case 4: ans=getpos(x) ;printf("%d\n",ans);break;
			case 5: ins(x);printf("%d\n",key[pre()]);del(x);break;
			case 6: ins(x);printf("%d\n",key[nxt()]);del(x);break;
		}
	}
	return 0;
}