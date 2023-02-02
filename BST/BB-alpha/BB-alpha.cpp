#include <bits/stdc++.h>
const double alpha = 0.7;
#define MAXN 2000001

inline int read() {
	int x;
	scanf("%d",&x); 
	return x;
}

namespace ScapegoatTree {
	struct node {
		int ch[2], val, size, tsize, real, fa;
	} e[MAXN];
	int cur[MAXN];
	int root, tot, cp, cnt, rb;
	
	int id(int u) {
		return e[e[u].fa].ch[1] == u;	
	}
	
	bool isbad(int u) {
		if (1.0 * e[u].tsize * alpha + 5 < 1.0 * e[e[u].ch[0]].tsize ||
			1.0 * e[u].tsize * alpha + 5 < 1.0 * e[e[u].ch[1]].tsize) 
			return true;
		else 
			return false;
	}

	void dfs(int u) {
		if (!u) return ;
		dfs(e[u].ch[0]);
		if (e[u].real) cur[++cp] = u;
		dfs(e[u].ch[1]);
	}

	void build(int l, int r, int &u, int fa = 0) {
		int mid = l + r >> 1;
		u = cur[mid];
		e[u].fa = fa;
		if (l == r) {
			e[u].ch[0] = e[u].ch[1] = 0;
			e[u].size = e[u].tsize = 1;
			return ;
		}
		if (l < mid) build(l, mid - 1, e[u].ch[0], u);
		else e[u].ch[0] = 0;
		build(mid + 1, r, e[u].ch[1], u);
		e[u].size = e[e[u].ch[0]].size + e[e[u].ch[1]].size + 1;
		e[u].tsize = e[e[u].ch[0]].tsize + e[e[u].ch[1]].tsize + e[u].real;
	}

	void rebuild(int &u) {
		cp = 0;
		dfs(u);
		if (cp) build(1, cp, u);
		else u = 0;
	}

	void insert(int &u, int val) {
		if (!u) {
			u = ++tot;
			e[u].val = val;
			e[u].real = e[u].size = e[u].tsize = 1;
			e[u].ch[0] = e[u].ch[1] = 0;
			return ;
		}
		e[u].size++, e[u].tsize++;
		if (e[u].val >= val) insert(e[u].ch[0], val);
		else insert(e[u].ch[1], val);
		if (isbad(u)) rb = u;
	}

	int kth(int k) {
		for (int u = root; u; ) {
			if (e[u].real && e[e[u].ch[0]].tsize + 1 == k)
				return e[u].val;
			if (e[e[u].ch[0]].tsize >= k)
				u = e[u].ch[0];
			else 
				k -= e[e[u].ch[0]].tsize + e[u].real,
				u = e[u].ch[1];
		}
	}

	int rank(int val) {
		int ans = 1;
		for (int u = root; u; ) {
			if (e[u].val >= val)
				u = e[u].ch[0];
			else 
				ans += e[e[u].ch[0]].tsize + e[u].real,
				u = e[u].ch[1];
		}
		return ans;
	}

	void pop_rk(int &u, int rk) {
		if (e[u].real && e[e[u].ch[0]].tsize + 1 == rk) {
			e[u].real = 0;
			e[u].tsize--;
			return ;
		}
		e[u].tsize--;
		if (e[e[u].ch[0]].tsize + e[u].real >= rk)
			pop_rk(e[u].ch[0], rk);
		else 
			pop_rk(e[u].ch[1], rk - e[e[u].ch[0]].tsize - e[u].real);
	}

	void pop(int val) {
		pop_rk(root, rank(val));
		if (1.0 * e[root].size * alpha > e[root].tsize)
			rebuild(root);
	}
};
using namespace ScapegoatTree;

int main() {
	int opt, x, Q;
	Q = read();
	while (Q--) {
		opt = read(); x = read();
		switch(opt) {
			case 1: 
				insert(root, x); 
				if (rb) {
					rebuild(rb == root ? root : e[e[rb].fa].ch[id(rb)]);
					rb = 0;	
				}
				break;
			case 2: pop(x); break;
			case 3: printf("%d\n", rank(x)); break;
			case 4: printf("%d\n", kth(x)); break;
			case 5: printf("%d\n", kth(rank(x) - 1)); break;
			case 6: printf("%d\n", kth(rank(x + 1))); break;
		}
	}
	return 0;
}
