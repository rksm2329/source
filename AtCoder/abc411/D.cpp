#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

struct Query {
  int op, p;
  string s;
};

int n, q;
vector<Query> Q;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 1, op, p; i <= q; i++) {
    cin >> op >> p;
    Q.push_back({op, p});
    if (op == 2) {
      string s;
      cin >> s;
      Q.back().s = s;
    }
  }
  reverse(Q.begin(), Q.end());
  int k = 0;
  for (const auto [op, p, s] : Q) {
    if ()
  }
  return 0;
}