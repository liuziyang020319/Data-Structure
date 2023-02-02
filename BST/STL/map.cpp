#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define Node pair<int,int>
map <int,int> s;
tree< Node ,null_type,less< Node >,splay_tree_tag,tree_order_statistics_node_update> T;
int n,op,x;
int main()
{
    scanf("%d",&n);
    for(register int i = 1; i <= n; i++)
        switch(scanf("%d%d",&op,&x), op)
        {
            case 1 :T.insert(Node(x,s[x]++));
                    break;
            case 2 :T.erase(Node(x,--s[x]));
                    break;
            case 3 :printf("%d\n",(int)T.order_of_key(Node(x,0))+1);
                    break;
            case 4 :printf("%d\n",T.find_by_order(x-1)->first);
                    break;
            case 5 :printf("%d\n",T.find_by_order(
                    T.order_of_key(Node(x,0))-1
                                                      )->first);
                    break;
            case 6 :printf("%d\n",T.find_by_order(
                    T.order_of_key(Node(x,s[x]-1))+(T.find(Node(x,0)) == T.end() ? 0 : 1)
                                                      )->first);
                    break;
            default:break;
        }
    return 0;
}