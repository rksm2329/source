#include <bits/stdc++.h>

using namespace std;

struct Func {
  int a, b, c, x, s;
  bool operator<(const Func &other) const {
    return s > other.s;
  }
} now;

int n, m;
priority_queue<Func> pq;

int main() {
  cin >> n >> m;
  now.x = 1;
  for (int i = 1; i <= n; i++) {
    cin >> now.a >> now.b >> now.c;
    now.s = now.a + now.b + now.c;
    pq.push(now);
  }
  for (int i = 1; i <= m; i++) {
    cout << pq.top().s << ' ';
    now = pq.top();
    pq.pop();
    now.x++;
    now.s = now.a * now.x * now.x + now.b * now.x + now.c;
    pq.push(now);
  }
  return 0;
}