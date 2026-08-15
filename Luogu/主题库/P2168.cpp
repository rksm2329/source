#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  long long w, h;
  bool operator<(const TreeNode &other) const {
    if (w != other.w) return w > other.w;
    return h > other.h;
  }
} ;

int n, k;
long long ans;
priority_queue<TreeNode> pq;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    long long w;
    cin >> w;
    pq.push({w, 1});
  }
  for (; (pq.size() - 1) % (k - 1); pq.push({0, 1}));
  while (pq.size() >= k) {
    long long hh = -1, ww = 0;
    for (int i = 1; i <= k; i++) {
      hh = max(hh, pq.top().h), ww += pq.top().w;
      pq.pop();
    }
    ans += ww;
    pq.push({ww, hh + 1});
  }
  cout << ans << '\n' << pq.top().h - 1;
  return 0;
}