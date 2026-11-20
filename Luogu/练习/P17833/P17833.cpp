#include <bits/stdc++.h>

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

const int MAXN = 2e6 + 10;

int n, L[MAXN], R[MAXN], dp[2][MAXN];
ll d, a[MAXN];

void Solve() {
  gi(n), gi(d);
  for (int i = 1; i <= n; gi(a[i++]));
  L[0] = 1, L[n + 1] = n + 1;
  for (int i = 1; i <= n; i++) {
    for (L[i] = L[i - 1]; L[i] < i && a[i] - a[L[i]] > d; L[i]++);
  }
  R[n + 1] = n;
  for (int i = n; i >= 1; i--) {
    for (R[i] = R[i + 1]; R[i] > i && a[R[i]] - a[i] > d; R[i]--);
  }
  for (int i = 1; i <= n; i++) {
    dp[0][i] = 1 + min(L[i + 1], i) - L[i] + (R[L[i]] == i) * (dp[0][L[i]] - 1);
  }
  for (int i = n; i >= 1; i--) {
    dp[1][i] = 1 + R[i] - max(R[i - 1], i) + (L[R[i]] == i) * (dp[1][R[i]] - 1);
  }
  ll ans = 0;
  for (int p = 1; p < n; p++) {
    int xl = L[p + 1], xr = min(p, L[p + 2]) - 1;
    int yl = max(p + 1, R[p - 1]) + 1, yr = R[p];
    ll cx = max(0, xr - xl + 1), cy = max(0, yr - yl + 1);
    if (L[p] < p && R[L[p]] == p + 1) cx += dp[0][L[p]] - 1;
    if (R[p + 1] > p + 1 && L[R[p + 1]] == p) cy += dp[1][R[p + 1]] - 1;
    ans += cx * cy;
  }
  print(ans), pc('\n');
}

int main() {
  int c, T;
  for (gi(c), gi(T); T--; Solve());
  return 0;
}