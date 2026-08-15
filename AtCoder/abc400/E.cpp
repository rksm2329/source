#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXV = 1e6 + 10;

int q, a[MAXV], res[MAXV];

bool C(int x) {
  set<int> s;
  for (; x > 1; s.insert(a[x]), x /= a[x]);
  return s.size() == 2;
}

void init(int n) {
  vector<int> pr;
  for (int i = 2; i <= n; i++) {
    if (!a[i]) {
      a[i] = i, pr.push_back(i);
    }
    for (int j : pr) {
      if (i * j > n) {
        break;
      }
      a[i * j] = j;
      if (i % j == 0) {
        break;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    res[i] = C(i) ? i : res[i - 1];
  }
}

void Solve() {
  ll x;
  cin >> x;
  ll q = res[int(sqrt(x))];
  cout << q * q << '\n';
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  init(MAXV - 1);
  for (cin >> q; q--; Solve());
  return 0;
}