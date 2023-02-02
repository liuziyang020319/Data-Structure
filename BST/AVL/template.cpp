#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 100000 + 10;
template<class T> inline void read(T &x) {
	char c = 0;
	int f = x = 0;
	while (c < 48 || c > 57) {
		if (c == '-')
			f = 1;
		c = getchar();
	}
	while (c > 47 && c < 58) x = (x << 3)+(x << 1)+(c & 15), c = getchar();
	if (f) x = -x;
}
template<class T,class... Args> inline void read(T &x, Args&... args) {
	read(x), read(args...);
}
template<class T> inline void write(T x) {
	if (x < 0) {
		putchar(45);
		write(-x);
		return;
	}
	if (x > 9) write(x / 10);
	putchar((x % 10) | 48);
}
struct AVLnode;
typedef AVLnode* AVLtree;
struct AVLnode {
	int data, high;
	int freq, size;
	AVLtree ls, rs;
	AVLnode(): data(0), high(1), freq(1), size(1), ls(NULL), rs(NULL){}
	AVLnode(int a): data(a), high(1), freq(1), size(1), ls(NULL), rs(NULL){}
};
inline int GetSize(AVLtree p) {
	if (p == NULL) return 0;
	return p->size;
}
inline int GetHigh(AVLtree p) {
	if (p == NULL) return 0;
	return p->high;
}
struct AVL {
	AVLtree root;
	inline void update(AVLtree& p) {
		p->size = GetSize(p->ls) + GetSize(p->rs) + p->freq;
		p->high = max(GetHigh(p->ls), GetHigh(p->rs)) + 1;
	}
	inline void LeftPlus(AVLtree& p) {
		AVLtree q;
		q = p->ls;
		p->ls = q->rs;
		q->rs = p;
		update(p);
		update(q);
		p = q;
	}
	inline void RightPlus(AVLtree& p) {
		AVLtree q;
		q = p->rs;
		p->rs = q->ls;
		q->ls = p;
		update(p);
		update(q);
		p = q;
	}
	inline void LeftRight(AVLtree& p) {
		RightPlus(p->ls);
		LeftPlus(p);
	}
	inline void RightLeft(AVLtree& p) {
		LeftPlus(p->rs);
		RightPlus(p);
	}
	inline void OutPut(AVLtree p) {
		if (p == NULL) return;
		OutPut(p->ls);
		for (int i = 1; i <= p->freq; ++i)
			write(p->data), putchar(32);
		OutPut(p->rs);
	}
	inline void output() {
		OutPut(root);
	}
	inline void Insert(AVLtree &p, int x) {
		if (p == NULL) {
			p = new AVLnode(x);
			return;
		}
		if (p->data == x) {
			++(p->freq);
			update(p);
			return;
		}
		if (p->data > x) {
			Insert(p->ls, x), update(p);
			if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
				if (x < p->ls->data)
					LeftPlus(p);
				else
					LeftRight(p);
			}
		}
		else {
			Insert(p->rs, x), update(p);
			if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
				if (x > p->rs->data)
					RightPlus(p);
				else
					RightLeft(p);
			}
		}
		update(p);
	}
	inline void insert(int x) {
		Insert(root, x);
	}
	inline void Erase(AVLtree& p, int x) {
		if (p == NULL) return;
		if (p->data > x) {
			Erase(p->ls, x), update(p);
			if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
				if (GetHigh(p->rs->rs) >= GetHigh(p->rs->ls))
					RightPlus(p);
				else
					RightLeft(p);
			}
		}
		else if(p->data < x) {
			Erase(p->rs, x), update(p);
			if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
				if (GetHigh(p->ls->ls) >= GetHigh(p->ls->rs))
					LeftPlus(p);
				else
					LeftRight(p);
			}
		}
		else {
			if (p->freq > 1) {
				--(p->freq);
				update(p);
				return;
			}
			if (p->ls && p->rs) {
				AVLtree q = p->rs;
				while (q->ls) q = q->ls;
				p->freq = q->freq;
				p->data = q->data, q->freq = 1;
				Erase(p->rs, q->data);
				update(p);
				if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
					if (GetHigh(p->ls->ls) >= GetHigh(p->ls->rs))
						LeftPlus(p);
					else
						LeftRight(p);
				}
			}
			else {
				AVLtree q = p;
				if (p->ls) p = p->ls;
				else if (p->rs) p = p->rs;
				else p = NULL;
				delete q;
				q = NULL;
			}
		}
		if (p == NULL) return;
		update(p);
	}
	inline void erase(int x) {
		Erase(root, x);
	}
	inline int get_val(AVLtree p, int rank) {
		if (GetSize(p->ls) >= rank) return get_val(p->ls, rank);
		if (GetSize(p->ls) + p->freq >= rank) return p->data;
		return get_val(p->rs, rank - GetSize(p->ls) - p->freq);
	}
	inline int GetVal(int rank) {
		return get_val(root, rank);
	}
	inline int get_rank(AVLtree p, int val) {
		if (p->data == val) return GetSize(p->ls) + 1;
		if (p->data > val) return get_rank(p->ls, val);
		return get_rank(p->rs, val) + GetSize(p->ls) + p->freq;
	}
	inline int GetRank(int val) {
		return get_rank(root, val);
	}
	inline int GetPrev(int val) {
		AVLtree ans = new AVLnode(-1LL << 42), p = root;
		while (p) {
			if (p->data == val) {
				if (p->ls) {
					p = p->ls;
					while (p->rs)
						p = p->rs;
					ans = p;
				}
				break;
			}
			if (p->data < val && p->data > ans->data) ans = p;
			p = p->data < val ? p->rs : p->ls;
		}
		return ans->data;
	}
	inline int GetNext(int val) {
		AVLtree ans = new AVLnode(1LL << 42), p = root;
		while (p) {
			if (p->data == val) {
				if (p->rs) {
					p = p->rs;
					while (p->ls)
						p = p->ls;
					ans = p;
				}
				break;
			}
			if (p->data > val && p->data < ans->data) ans = p;
			p = p->data < val ? p->rs : p->ls;
		}
		return ans->data;
	}
};
int n, x, opt;
AVL a;
signed main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		read(opt, x);
		switch(opt) {
			case 1: a.insert(x); break;
			case 2: a.erase(x); break;
			case 3: write(a.GetRank(x)), putchar(10); break;
			case 4: write(a.GetVal(x)), putchar(10); break;
			case 5: write(a.GetPrev(x)), putchar(10); break;
			case 6: write(a.GetNext(x)), putchar(10); break;
		}
	}
	return 0;
}