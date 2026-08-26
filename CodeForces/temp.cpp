#include <bits/stdc++.h>
#define ENDL '\n', cout.flush()
#define randpos (rnd() % n + 1)

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

const int MAXN = 1e2 + 10, MAXV = 2e5 + 10;

ll n, val[MAXN][MAXN];
bool vis[MAXV];
vector<int> pr;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void sieve(int n) {
  vis[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) pr.push_back(i);
    for (int p : pr) {
      if (i * p > n) break;
      vis[i * p] = 1;
      if (i % p == 0) break;
    }
  }
}

ll qlcm(int x, int y) {
  cout << "? " << x << ' ' << y << ENDL;
  ll res;
  cin >> res;
  return res;
}

int qval(int x) {
  ll val = 0;
  for (int i = 1; i <= 20; i++) {
    int k;
    do k = randpos; while (k == x);
    val = gcd(qlcm(x, k), val);
  }
  return val;
}

void Solve() {
  cin >> n;
  if (n <= 100) {
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) val[i][j] = val[j][i] = qlcm(i, j);
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      int k = 0;
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        k = gcd(val[i][j], k);
      }
      cout << k << ' ';
    }
    cout << ENDL;
    return;
  }
  pll mx;
  int cnt = 0;
  for (int i = 1; i <= 200; i++) {
    ll k = randpos, val = qval(k);
    if (val > mx.first && !vis[val]) mx = {val, k};
  }
  vector<int> res;
  for (int i = 1; i <= n; i++) {
    res.push_back(i == mx.second ? mx.first : qlcm(mx.second, i) / mx.first);
  }
  cout << "! ";
  for (int x : res) cout << x << ' ';
  cout << ENDL;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sieve(MAXV - 1);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}