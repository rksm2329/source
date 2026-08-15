#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4e6 + 10;

int n, a[MAXN];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pq.push(a[i]);
  }
  int ans = 0;
  while (pq.size() > 1) {
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    pq.push(x + y);
    ans += x * y;
  }
  cout << ans;
  return 0;
}