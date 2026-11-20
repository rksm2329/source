#include <bits/stdc++.h>
#define illegal() { cout << "No\n"; return; }

using namespace std;
using ll = long long;
using pii = pair<int, bool>;

const int MAXN = 1e6 + 10;

struct Node {
  int l, r;
  bool flag;
};

struct List {
  int pre, nxt;
  bool val;
} lst[MAXN];

string s, t;
int n, m;
vector<Node> T;
vector<pii> intrv;
bool ok[MAXN];

bool check(const Node &now) {
  auto &[L, R, flag] = now;
  if (L > 1 && intrv[L].second != flag) return 0;
  if (R < m && intrv[R].second != flag) return 0;
  queue<int> q;
  for (int i = L; i <= R; i++) {
    if (intrv[i].second != flag) {
      if ((i > L && intrv[i].first < intrv[i - 1].first) || (i < R && intrv[i].first < intrv[i + 1].first)) q.push(i);
      if (i > L && ok[i - 1]) return 0;
    }
  }
  while (!q.empty()) {
    int now = q.front(); q.pop();
    if (ok[now]) continue;
    if (now == 1 && lst[now].nxt) {
      int r = lst[now].nxt;
      if (intrv[now].first < intrv[r].first) {
        int rr = lst[r].nxt;
        intrv[r].first += intrv[now].first;
        lst[r].pre = 0;
        lst[now] = {0, 0, 0};
        ok[now] = 1;
        if (rr && rr <= R && intrv[r].first > intrv[rr].first) q.push(rr);
        continue;
      }
    }
    if (now == m && lst[now].pre) {
      int l = lst[now].pre;
      if (intrv[now].first < intrv[l].first) {
        int ll = lst[l].pre;
        intrv[l].first += intrv[now].first;
        lst[l].nxt = 0;
        lst[now] = {0, 0, 0};
        ok[now] = 1;
        if (ll && ll >= L && intrv[l].first > intrv[ll].first) q.push(ll);
        continue;
      }
    }
    if (lst[now].pre && lst[now].nxt) {
      int l = lst[now].pre, mid = lst[now].nxt, r = lst[mid].nxt;
      int ll = lst[l].pre, rr = r;
      int len = intrv[l].first + intrv[now].first + intrv[mid].first;
      lst[l].nxt = r;
      if (r) lst[r].pre = l;
      intrv[l].first = len;
      lst[mid] = {0, 0, 0};
      lst[now] = {0, 0, 0};
      ok[now] = 1;
      if (ll >= L && intrv[ll].first < len && !ok[ll]) q.push(ll);
      if (rr && rr <= R && intrv[rr].first < len && !ok[rr]) q.push(rr);
    }
  }
  for (int i = L; i <= R; i++) {
    if (intrv[i].second != flag && !ok[i]) return 0;
  }
  return 1;
}

void Solve() {
  cin >> s >> t;
  n = s.size();
  s = '#' + s;
  t = '#' + t;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && t[i] != t[i - 1] && s[i] == s[i - 1]) illegal();
  }
  intrv = {{0, 0}};
  int last = 1;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && s[i] != s[i - 1]) {
      intrv.push_back({i - last, s[i - 1] == '+'});
      last = i;
    }
  }
  intrv.push_back({n - last + 1, s[n] == '+'});
  last = 0, m = intrv.size() - 1;
  T.clear();
  for (int i = 1, r = 0; i <= m; i++) {
    lst[i].pre = i - 1, lst[i].nxt = i + 1;
    r += intrv[i].first;
    if (r == n || t[r] != t[r + 1]) {
      T.push_back({last + 1, i, t[r] == '+'});
      last = i;
    }
  }
  lst[m].nxt = 0;
  fill(ok + 1, ok + m + 1, 0);
  for (const Node &interval : T) {
    if (!check(interval)) illegal();
  }
  cout << "Yes\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  for (cin >> T; T--; Solve());
  return 0;
}