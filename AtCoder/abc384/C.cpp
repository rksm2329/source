#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[5];
vector<pair<int, string>> v;

void dfs(int x, int sum, string s) {
  if (x == 5) {
    if (sum) {
      v.push_back({sum, s});
    }
    return;
  }
  dfs(x + 1, sum + a[x], s + char(x + 'A'));
  dfs(x + 1, sum, s);
}

bool cmp(pair<int, string> &i, pair<int, string> &j) {
  return i.first > j.first || (i.first == j.first && i.second < j.second);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 0; i < 5; i++) cin >> a[i];
  dfs(0, 0, "");
  sort(v.begin(), v.end(), cmp);
  for (pair<int, string> x : v) {
    cout << x.second << '\n';
  }
  return 0;
}