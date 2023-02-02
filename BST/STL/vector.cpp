#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<vector>
#include<algorithm>
#define inf 1000000000
using namespace std;

int n;
vector<int> a;
void insert(int x)
{
	a.insert(upper_bound(a.begin(),a.end(),x),x);
	return;
}
void del(int x)
{
	a.erase(lower_bound(a.begin(),a.end(),x));
	return;
}
int find(int x)
{
	return lower_bound(a.begin(),a.end(),x)-a.begin()+1;
}
int main()
{
	scanf("%d",&n);
	a.reserve(200000);
	int f,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&f,&x);
		switch(f)
		{
		case 1:insert(x);break;
		case 2:del(x);break;
		case 3:printf("%d\n",find(x));break;
		case 4:printf("%d\n",a[x-1]);break;
		case 5:printf("%d\n",*--lower_bound(a.begin(),a.end(),x));break;
		case 6:printf("%d\n",*upper_bound(a.begin(),a.end(),x));break;
		}
	}
	return 0;
}
