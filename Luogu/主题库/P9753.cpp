#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;
int n, dp[MAXN], a[MAXN][26], to[MAXN];
char s[MAXN];
long long ans;

int main() {
  cin >> n;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    to[i] = i;
    int x = a[to[i - 1]][s[i] - 'a'];
    if (x) {
      to[i] = to[x - 1], dp[i] = dp[x - 1] + 1;
    }
    a[to[i]][s[i] - 'a'] = i, ans += dp[i];
  }
  cout << ans;
  return 0;
}