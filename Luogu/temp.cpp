#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e6 + 10;

int n, k, mif[MAXN], c[MAXN];
bool vis[MAXN];
vector<int> pr;

void sieve(int n) {
  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      pr.push_back(i), mif[i] = i;
    }
    for (int p : pr) {
      if (i * p > n) break;
      vis[i * p] = 1, mif[i * p] = p;
      if (i % p == 0) break;
    }
  }
}

void add(int x, int &cnt) {
  for (; x > 1; x /= mif[x]) cnt -= !++c[mif[x]];
}

void del(int x, int &cnt) {
  for (; x > 1; x /= mif[x]) cnt += !c[mif[x]]--;
}

int main() {
  freopen("num.in", "r", stdin);
  freopen("num.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  if (k == 1) {
    cout << 1ll * n * (n + 1) / 2;
    return 0;
  }
  sieve(n);
  int cnt = 0;
  for (int i = 2; i * i <= k; i++) {
    if (k % i == 0) {
      cnt++;
      for (; k % i == 0; k /= i, c[i]--);
    }
  }
  if (k > 1) {
    if (k > n) {
      cout << 0;
      return 0;
    }
    cnt++, c[k]--;
  }
  ll ans = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    add(i, cnt);
    for (; j <= i && !cnt; del(j++, cnt));
    ans += j - 1;
  }
  cout << ans;
  return 0;
}