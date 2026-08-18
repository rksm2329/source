#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN], pre[MAXN], cnt[MAXN];
vector<int> lsh;

int rnk(int x) {
  return lower_bound(lsh.begin(), lsh.end(), x) - lsh.begin() + 1;
}

bool check(int x) {
  fill(cnt + 1, cnt + m + 1, 0);
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  multiset<int> st;
  for (int i = 1; i <= m; i++) {
    if (!cnt[i]) continue;
    while (cnt[i] && !st.empty()) {
      auto it = st.lower_bound(i - 1);
      if (it == st.end() || *it != i - 1) break;
      st.erase(it), st.insert(i);
      cnt[i]--;
    }
    if (cnt[i] && i + x - 1 <= m) {
      for (int j = i + 1; j <= i + x - 1; j++) {
        if (cnt[j] < cnt[i]) return 0;
        cnt[j] -= cnt[i];
      }
      for (int j = 1; j <= cnt[i]; j++) st.insert(i + x - 1);
      cnt[i] = 0;
    }
    if (cnt[i]) return 0;
  }
  return 1;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    lsh.push_back(a[i]);
  }
  sort(lsh.begin(), lsh.end());
  lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());
  m = lsh.size();
  for (int i = 2; i <= m; i++) {
    pre[i] = pre[i - 1] + (lsh[i - 1] != lsh[i - 2] + 1);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = rnk(a[i]) + pre[rnk(a[i])];
  }
  m += pre[m];
  sort(a + 1, a + n + 1);
  int l = 1, r = n;
  while (l < r) {
    int mid = l + r + 1 >> 1;
    check(mid) ? l = mid : r = mid - 1;
  }
  cout << l;
  return 0;
}