#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using i128 = __int128_t;

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

const int MAXN = 2e5 + 10;

struct Note {
  ll x, t, w, s;
  int id;
} a[MAXN];

struct Finger {
  ll l, r;
} f[15], init_f[15];

int n, k, L_min[MAXN];
i128 Sw[MAXN], Ss[MAXN], dp[MAXN];
int q[MAXN], head = 1, tail = 0;

bool cmp(const Note &i, const Note &j) {
  if (i.t != j.t) return i.t < j.t;
  return i.x < j.x;
}

inline i128 get_X(int L) { return (i128)L; }
inline i128 get_Y(int L) { return dp[L - 1] - Sw[L - 1] + (i128)L * Ss[L - 1]; }

bool check(int l1, int l2, int l3) {
  i128 x1 = get_X(l1), y1 = get_Y(l1);
  i128 x2 = get_X(l2), y2 = get_Y(l2);
  i128 x3 = get_X(l3), y3 = get_Y(l3);
  return (y2 - y1) * (x3 - x2) <= (y3 - y2) * (x2 - x1);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> k;
  for (int i = 1; i <= k; i++) {
    ll p;
    cin >> p;
    init_f[i] = f[i] = {p - 1, p + 1};
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].t >> a[i].w >> a[i].s;
    a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    Sw[i] = Sw[i - 1] + a[i].w + (i128)i * a[i].s;
    Ss[i] = Ss[i - 1] + a[i].s;
  }
  int cur_L = 1;
  for (int i = 1; i <= n; i++) {
    ll A = a[i].x - a[i].t;
    ll B = a[i].x + a[i].t;
    int best = -1;
    ll max_len = -1;
    for (int j = 1; j <= k; j++) {
      if (A <= f[j].l && f[j].r <= B) {
        ll len = f[j].r - f[j].l;
        if (len > max_len) {
          max_len = len;
          best = j;
        }
      }
    }
    if (~best) {
      f[best] = {A, B};
      L_min[i] = cur_L;
    } else {
      cur_L = i;
      for (int j = 1; j <= k; j++) f[j] = init_f[j];
      best = -1, max_len = -1;
      for (int j = 1; j <= k; j++) {
        if (A <= f[j].l && f[j].r <= B) {
          ll len = f[j].r - f[j].l;
          if (len > max_len) {
            max_len = len;
            best = j;
          }
        }
      }
      if (~best) {
        f[best] = {A, B};
        L_min[i] = i;
      } else {
        L_min[i] = i + 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1];
    if (L_min[i] <= i) {
      int L_new = i;
      while (tail - head + 1 >= 2 && check(q[tail - 1], q[tail], L_new)) tail--;
      q[++tail] = L_new;
      while (head <= tail && q[head] < L_min[i]) head++;
      i128 M = Ss[i];
      while (tail - head + 1 >= 2) {
        i128 y1 = get_Y(q[head]), x1 = get_X(q[head]);
        i128 y2 = get_Y(q[head + 1]), x2 = get_X(q[head + 1]);
        if (y2 - y1 >= M * (x2 - x1)) head++;
        else break;
      }
      if (head <= tail) {
        int L = q[head];
        i128 val = dp[L - 1] + Sw[i] - Sw[L - 1] - (i128)L * (Ss[i] - Ss[L - 1]);
        if (val > dp[i]) dp[i] = val;
      }
    }
  }
  print(dp[n]);
  return 0;
}