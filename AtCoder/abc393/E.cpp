#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e6 + 10;
const int MAXV = 1e6 + 10;

int n, k, a[MAXN], ans[MAXV], cnt[MAXV];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  for (int i = 1; i < MAXV; i++) {
    int cntk = 0;
    for (int j = i; j < MAXV; j += i) {
      cntk += cnt[j];
    }
    if (cntk >= k) {
      for (int j = i; j < MAXV; j += i) {
        ans[j] = i;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[a[i]] << '\n';
  }
  return 0;
}