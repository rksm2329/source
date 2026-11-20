#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5, B = 360;

int n, m, b, a[N + 10], cnt[N + 10], pos[N + 10], last[B];
bool ans[N + 10];
bitset<N + 1> bs1, bs2;

struct Query {
  int op, l, r, x, id;
  bool operator<(const Query &oth) const {
    int ba = (l - 1) / b + 1;
    int bb = (oth.l - 1) / b + 1;
    if (ba != bb) return ba < bb;
    return ba & 1 ? r < oth.r : r > oth.r;
  }
};

struct Node {
  int l, r, id;
  bool operator<(const Node &oth) const {
    return r < oth.r;
  }
};

vector<Query> qry;
vector<Node> vec[N + 10];

void add(int x) {
  cnt[a[x]]++;
  if (!bs1[a[x]]) bs1[a[x]] = bs2[N - a[x]] = 1;
}

void del(int x) {
  cnt[a[x]]--;
  if (bs1[a[x]] && !cnt[a[x]]) bs1[a[x]] = bs2[N - a[x]] = 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  b = max(1.0, n / sqrt(m));
  for (int i = 1, op, l, r, x; i <= m; i++) {
    cin >> op >> l >> r >> x;
    if (op == 4 && x <= b) {
      vec[x].push_back({l, r, i});
    }
    else qry.push_back({op, l, r, x, i});
  }
  for (int now = 1; now <= b; now++) {
    sort(vec[now].begin(), vec[now].end());
    fill(pos + 1, pos + N + 1, 0);
    for (int i = 1, j = 0; i <= n; i++) {
      pos[a[i]] = i;
      if (a[i] % now == 0 && pos[a[i] / now]) last[now] = max(last[now], pos[a[i] / now]);
      if (a[i] * now <= N && pos[a[i] * now]) last[now] = max(last[now], pos[a[i] * now]);
      for (; j < vec[now].size() && vec[now][j].r < i; j++);
      for (; j < vec[now].size() && vec[now][j].r == i; j++) {
        ans[vec[now][j].id] = vec[now][j].l <= last[now];
      }
    }
  }
  sort(qry.begin(), qry.end());
  int L = 1, R = 0;
  for (auto &[op, l, r, x, id] : qry) {
    for (; R < r; add(++R));
    for (; L > l; add(--L));
    for (; R > r; del(R--));
    for (; L < l; del(L++));
    if (op == 1) ans[id] = (bs1 & (bs1 >> x)).count();
    else if (op == 2) ans[id] = (bs1 & (bs2 >> (N - x))).count();
    else if (op == 3) {
      for (int i = 1; i * i <= x; i++) {
        if (x % i == 0 && bs1[i] && bs1[x / i]) {
          ans[id] = 1;
          break;
        }
      }
    } else {
      for (int i = x; i <= n; i += x) {
        if (bs1[i] && bs1[i / x]) {
          ans[id] = 1;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << (ans[i] ? "yuno\n" : "yumi\n");
  }
  return 0;
}