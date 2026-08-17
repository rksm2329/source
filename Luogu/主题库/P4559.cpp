#include <bits/stdc++.h>
#define mid (l + r >> 1)

using namespace std;
using ll = long long;

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' ' && __c != '\n' && __c != '\r'; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

const int N = 1e6, P = 1.1e7;

struct Node {
  int ls, rs, v;
  ll sum;
} pool[P];

int n, m, a[N + 10], top, root[N + 10];

void update(int &cur, int ver, int l, int r, int pos) {
  pool[cur = ++top] = pool[ver];
  pool[cur].v++, pool[cur].sum += pos;
  if (l == r) return;
  if (pos <= mid) update(pool[cur].ls, pool[ver].ls, l, mid, pos);
  else update(pool[cur].rs, pool[ver].rs, mid + 1, r, pos);
}

int query(int cur, int ver, int l, int r, int k) {
  if (l == r) return l;
  int lc = pool[pool[cur].ls].v - pool[pool[ver].ls].v;
  if (k <= lc) return query(pool[cur].ls, pool[ver].ls, l, mid, k);
  return query(pool[cur].rs, pool[ver].rs, mid + 1, r, k - lc);
}

ll query(int cur, int ver, int l, int r, int L, int R) {
  if (L > R) return 0;
  if (L <= l && R >= r) return pool[cur].sum - pool[ver].sum;
  ll ans = 0;
  if (L <= mid) ans += query(pool[cur].ls, pool[ver].ls, l, mid, L, R);
  if (R > mid) ans += query(pool[cur].rs, pool[ver].rs, mid + 1, r, L, R);
  return ans;
}

int find(int L, int R, int k) {
  int l = 1, r = R - L + 2;
  while (l < r) {
    query(root[R], root[L - 1], 1, N, mid) >= k + mid - 1 ? r = mid : l = mid + 1;
  }
  return l;
}

int main() {
  gi(n), gi(m);
  for (int i = 1, x; i <= n; i++) {
    gi(x);
    update(root[i], root[i - 1], 1, N, x);
  }
  for (int i = 1, l, r, k; i <= m; i++) {
    gi(l), gi(r), gi(k);
    ll x = find(l, r, k);
    int xth = x == r - l + 2 ? N + 1 : query(root[r], root[l - 1], 1, N, x);
    int prexth = x == 1 ? 0 : query(root[r], root[l - 1], 1, N, x - 1);
    print((k * 2 + x - 2) * (x - 1) / 2 - query(root[r], root[l - 1], 1, N, 1, prexth) + query(root[r], root[l - 1], 1, N, xth, N) - (k + x - 1 + k + r - l) * (r - l - x + 2) / 2);
    pc('\n');
  }
  return 0;
}