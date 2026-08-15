#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, x, d[20];
map<vector<int>, ll> mp, s;
vector<int> k, m;

void dfs(int o) {
  if (o == n) {
    for (int i = 0; i < d[x]; i++) {
      k[x] = i;
      s[m] += mp[k];
    }
    return;
  }
  if (o == x) {
    k.push_back(-1);
    dfs(o + 1);
    k.pop_back();
    return;
  }
  for (int i = 0; i < d[o]; i++) {
    k.push_back(i);
    m.push_back(i);
    dfs(o + 1);
    k.pop_back();
    m.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> x;
  int sum = 1;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    sum *= d[i];
  }
  for (int i = 0, val; i < sum; i++) {
    vector<int> v;
    for (int j = 0, l; j < n; j++) {
      cin >> l;
      v.push_back(l);
    }
    cin >> val;
    mp[v] = val;
  }
  dfs(0);
  for (pair<vector<int>, ll> i : s) {
    for (int j : i.first) {
      cout << j << ' ';
    }
    cout << i.second << '\n';
  }
  return 0;
}