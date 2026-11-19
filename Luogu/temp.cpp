#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, q;
string s;

class SegTree {
private:
	struct Node {
		int lv, rv, v, sum, mi, len;
		Node operator+(const Node &oth) {
			Node res = {0, 0, 0, 0};
			res.v = max({v, oth.v, rv + oth.lv});
			res.lv = lv, res.rv = oth.rv;
			if (!sum && mi >= 0) res.lv = max(res.lv, len + oth.lv);
			if (!oth.sum && sum + oth.mi >= 0) res.rv = max(res.rv, oth.len + rv);
			res.sum = sum + oth.sum, res.mi = min(mi, sum + oth.mi), res.len = len + oth.len;
			if (!res.sum && res.mi >= 0) res.v = res.lv = res.rv = len + oth.len;
			return res;
		}
	} dat[MAXN << 2];
	const Node I = {0, 0, 0, 0};
	#define mid (l + r >> 1)
	#define lc root << 1
	#define rc root << 1 | 1
	#define LC lc, l, mid
	#define RC rc, mid + 1, r

public:
	void build(int root, int l, int r) {
		if (l == r) {
			dat[root] = {0, 0, 0, s[l] == '(' ? 1 : -1, s[l] == '(' ? 1 : -1, 1};
			return;
		}
		build(LC), build(RC);
		dat[root] = dat[lc] + dat[rc];
	}
	void update(int root, int l, int r, int pos) {
		if (l == r) {
			dat[root].sum = -dat[root].sum, dat[root].mi = -dat[root].mi;
			return;
		}
		pos <= mid ? update(LC, pos) : update(RC, pos);
		dat[root] = dat[lc] + dat[rc];
	}
	Node query(int root, int l, int r, int L, int R) {
		if (L <= l && R >= r) return dat[root];
		Node ans = I;
		bool flag = 0;
		if (L <= mid) {
			Node res = query(LC, L, R);
			if (!flag) flag = 1, ans = res;
			else ans = ans + res;
		}
		if (R > mid) {
			Node res = query(RC, L, R);
			if (!flag) flag = 1, ans = res;
			else ans = ans + res;
		}
		return ans;
	}
} T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q >> s;
	s = '#' + s;
	T.build(1, 1, n);
	for (int i = 1, op; i <= q; i++) {
		cin >> op;
		if (op == 1) {
			int k;
			cin >> k;
			T.update(1, 1, n, k);
		} else {
			int l, r;
			cin >> l >> r;
			cout << T.query(1, 1, n, l, r).v << '\n';
		}
	}
	return 0;
}