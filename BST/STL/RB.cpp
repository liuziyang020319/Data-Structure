#include<bits/stdc++.h>
#include<bits/extc++.h>
#define N 100005
#define inf 0x3f3f3f3f
#define endl '\n'
#define debug cerr<<__LINE__<<endl
using namespace std;
using namespace __gnu_pbds;
int n,m;
tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>t;
inline int read(){
    int x;
    scanf("%d",&x);
    return x;
}
inline void write(register long long x){
    printf("%lld",x);
}
main(void){
    n=read();
    for(register int i=1;i<=n;i++){
        const register long long op=read(),x=read();
        if(op==1) t.insert((x<<20)+i);
        else if(op==2) t.erase(t.lower_bound((x<<20)));
        else if(op==3) write(t.order_of_key((x<<20))+1),putchar('\n');
        else if(op==4) write((*t.find_by_order(x-1))>>20),putchar('\n');
        else if(op==5) write((*--t.lower_bound((x<<20)))>>20),putchar('\n');
        else write((*t.upper_bound((x<<20)+n))>>20),putchar('\n');
    }
    return 0;
}
