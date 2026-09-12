#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e7 + 10;

bool vis[MAXN];
vector<int> pr;
int n, numto[10], charto[26];
string s;

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

int pow10(int x) {
  int ans = 1;
  for (; x--; ans *= 10);
  return ans;
}

bool check(string t) {
  memset(numto, -1, sizeof numto);
  memset(charto, -1, sizeof charto);
  for (int i = 0; i < n; i++) {
    int x = s[i] - 'a', y = t[i] - '0';
    if (~charto[x] && charto[x] != y || ~numto[y] && numto[y] != x) return 0;
    charto[x] = y, numto[y] = x;
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sieve(MAXN - 1);
  cin >> s;
  n = s.size();
  for (int i = pow10(n - 1); i < pow10(n); i++) {
    if (vis[i]) continue;
    if (check(to_string(i))) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}