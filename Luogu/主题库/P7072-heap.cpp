#include <bits/stdc++.h>

using namespace std;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int n, w, ww;

void push(int x) {
  (x < pq1.top() ? pq1.push(x) : pq2.push(x));
  if (pq2.size() < ww) {
    pq2.push(pq1.top()); pq1.pop();
  }
  if (pq2.size() > ww) {
    pq1.push(pq2.top()); pq2.pop();
  }
}

int main() {
  cin >> n >> w;
  pq1.push(0);
  for (int i = 1, x; i <= n; i++) {
    ww = max(1, i * w / 100);
    cin >> x;
    push(x);
    cout << pq2.top() << ' ';
  }
  return 0;
}