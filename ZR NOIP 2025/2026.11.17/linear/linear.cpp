#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

struct Node {
  ll g, cnt;
  vector<ll> path;
  Node (ll x, ll y) : g(gcd(x, y)), cnt(-1) {
    vector<pll> now;
    while (x != y) {
      if (x > y) {
        ll k = (x - 1) / y;
        now.push_back({0, k});
        x -= k * y;
      } else {
        ll k = (y - 1) / x;
        now.push_back({1, k});
        y -= k * x;
      }
    }
    if (!now.empty()) {
      this->cnt = now.back().first;
      for (auto it = now.rbegin(); it != now.rend(); it++) this->path.push_back((*it).second);
    }
  };
  bool operator<(const Node &oth) const {
    if (g != oth.g) return g < oth.g;
    if (cnt != oth.cnt) return cnt < oth.cnt;
    return path < oth.path;
  }
};

int n, q;

void Solve() {
  cin >> n >> q;
  vector<Node> arr;
  for (ll i = 1, x, y; i <= n; i++) {
    cin >> x >> y;
    arr.push_back(Node(x, y));
  }
  sort(arr.begin(), arr.end());
  for (ll x, y; q--; ) {
    cin >> x >> y;
    Node now = Node(x, y);
    if (now.path.empty()) {
      int l = lower_bound(arr.begin(), arr.end(), now.g, [] (const Node &i, const ll j) {
        return i.g < j;
      }) - arr.begin();
      int r = upper_bound(arr.begin(), arr.end(), now.g, [] (const ll i, const Node &j) {
        return i < j.g;
      }) - arr.begin();
      cout << r - l << '\n';
      continue;
    }
    int m = now.path.size() - 1;
    int l = lower_bound(arr.begin(), arr.end(), pll{now.g, now.cnt}, [] (const Node &i, const pll &j) {
      return pll{i.g, i.cnt} < j;
    }) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), pll{now.g, now.cnt}, [] (const pll &i, const Node &j) {
      return i < pll{j.g, j.cnt};
    }) - arr.begin();
    auto check = [&] (const int id) {
      for (int j = 0; j < m; j++) {
        if (arr[id].path.size() <= j) return -1;
        if (arr[id].path[j] != now.path[j]) return arr[id].path[j] < now.path[j] ? -1 : 1;
      }
      return 0;
    };
    auto find = [&] (bool flag, int l, int r) {
      while (l < r) {
        int mid = l + r >> 1, res = check(mid);
        res < 0 || (flag & !res) ? l = mid + 1 : r = mid;
      }
      return l;
    };
    auto findpos = [&] (int l, int r) {
      while (l < r) {
        int mid = l + r >> 1;
        arr[mid].path.size() <= m || arr[mid].path[m] < now.path[m] ? l = mid + 1 : r = mid;
      }
      return l;
    };
    auto calc = [&] (int l, int r) {
      return find(1, l, r) - findpos(find(0, l, r), find(1, l, r));
    };
    cout << calc(l, r) << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}