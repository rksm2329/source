#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, m, a[MAXN];

int main() {
  cin >> n >> m;
  priority_queue<int> pq1;
  priority_queue<int, vector<int>, greater<int>> pq2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1, x, last = 0; i <= m; i++) {
    cin >> x;
    for (int j = last + 1; j <= x; j++) {
      pq1.push(a[j]);
      if (pq1.size() == i) pq2.push(pq1.top()), pq1.pop();
    }
    last = x;
    cout << pq2.top() << '\n';
    pq1.push(pq2.top()), pq2.pop();
  }
  return 0;
}