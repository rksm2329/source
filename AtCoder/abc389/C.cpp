#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;

int q;
pair<ll, ll> que[MAXN << 1];

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> q;
  ll m = 0;
  int head = 1, tail = 0;
  for (ll op, x; q--; ) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      que[++tail] = {x, que[tail].first + que[tail].second};
    } else if (op == 2) {
      m += que[head].first;
      head++;
    } else {
      cin >> x;
      cout << que[head + x - 1].second - m << '\n';
    }
  }
  return 0;
}