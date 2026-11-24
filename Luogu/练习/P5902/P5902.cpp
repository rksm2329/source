#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int MAXN = 5e5 + 10, INF = 2e9;

namespace io {
  const int __SIZE = (1 << 21) + 1;
  char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
  #define Gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
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

struct BIT {
  int dat[MAXN], n;
  void init(int n) {
    this->n = n;
    fill(dat + 1, dat + n + 1, -INF);
  }
  void add(int x, int val) {
    for (; x <= n; x += x & -x)
      dat[x] = max(dat[x], val);
  }
  int query(int x) {
    int res = -INF;
    for (; x; x -= x & -x)
      res = max(res, dat[x]);
    return res;
  }
} T[2];

int n, u, d, s, f[MAXN], g[MAXN];
vector<pii> arr[MAXN];

int main() {
  gi(n), gi(u), gi(d), gi(s);
  int maxt = 0, L = s;
  for (int i = 1, t, l, m; i <= n; i++) {
    gi(t), gi(l), gi(m);
    maxt = max(maxt, t), L = max(L, l);
    arr[t].push_back({l, m});
  }
  T[0].init(L), T[1].init(L);
  T[0].add(L - s + 1, -s * u);
  T[1].add(s, s * d);
  for (int i = 1; i <= maxt; i++) {
    if (arr[i].empty()) continue;
    sort(arr[i].begin(), arr[i].end());
    int k = arr[i].size();
    for (int j = 0; j < k; j++) {
      auto [l, m] = arr[i][j];
      int now = max(T[0].query(L - l) + l * u,
                    T[1].query(l) - l * d) + m;
      f[j] = g[j] = now;
    }
    for (int j = 1; j < k; j++) {
      int dx = arr[i][j].first - arr[i][j - 1].first;
      f[j] = max(f[j], f[j - 1] - dx * d + arr[i][j].second);
    }
    for (int j = k - 2; j >= 0; j--) {
      int dx = arr[i][j + 1].first - arr[i][j].first;
      g[j] = max(g[j], g[j + 1] - dx * u + arr[i][j].second);
    }
    for (int j = 0; j < k; j++) {
      int l = arr[i][j].first;
      int now = max(f[j], g[j]);
      T[0].add(L - l + 1, now - l * u);
      T[1].add(l, now + l * d);
    }
  }
  int ans = max(T[0].query(L - s) + s * u,
                T[1].query(s) - s * d);
  print(max(0, ans));
  return 0;
}