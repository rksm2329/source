#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using i128 = __int128;

const int MAXN = 5e5 + 10;

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
  template <class I> inline void println(I x) { print(x), pc('\n'); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print; using io::println;

int n;
pll arr[MAXN];

ll gcd(ll i, ll j) {
  for (; j; i %= j, swap(i, j));
  return i;
}

pll frac(ll x, ll y) {
  ll d = gcd(abs(x), abs(y));
  return {x / d, y / d};
}

array<i128, 5> get(pll p, pll q) {
  auto [x1, y1] = p;
  auto [x2, y2] = q;
  if (y1 == y2) return {0, 1, 1, -y1, 1};
  auto [b, c] = frac(x2 - x1, y1 - y2);
  auto [d, e] = frac(x1 * y2 - x2 * y1, y1 - y2);
  return {1, b, c, d, e};
}

int main() {
  gi(n);
  for (int i = 1; i <= n; i++) {
    auto &[x, y] = arr[i];
    gi(x), gi(y);
  }
  map<array<i128, 5>, int> cnt;
  for (int i = 1; i <= n; i++) {
    for (int _ : {1, 2}) {
      if (i + _ > n) break;
      cnt[get(arr[i], arr[i + _])]++;
    }
  }
  vector<pair<int, array<i128, 5>>> vec;
  for (pair<array<i128, 5>, int> now : cnt) {
    vec.push_back({now.second, now.first});
  }
  int cur = 0;
  sort(vec.begin(), vec.end(), greater<pair<int, array<i128, 5>>>());
  for (pair<int, array<i128, 5>> now : vec) {
    auto [a, b, c, d, e] = now.second;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      auto &[x, y] = arr[i];
      res += a * c * e * x + b * e * y + c * d == 0;
    }
    if (res > (n >> 1)) {
      pstr("Yes\n");
      print(a * c * e), pc(' ');
      print(b * e), pc(' ');
      print(c * d), pc(' ');
      return 0;
    }
    if (++cur > 7) break;
  }
  pstr("No");
  return 0;
}