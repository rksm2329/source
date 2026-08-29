#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
vector<int> vec;
vector<vector<int>> ans;

void dfs(int u, int lst) {
  if (u == 0) {
    vector<int> x = vec;
    reverse(x.begin(), x.end());
    ans.push_back(x);
    return;
  }
  if (u == 1) {
    vec.push_back(lst);
    dfs(0, 0);
    vec.pop_back();
    return;
  }
  for (int i = lst / u; ~i; i--) {
    vec.push_back(i);
    dfs(u - 1, lst - i * u);
    vec.pop_back();
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> k;
  dfs(n, k);
  sort(ans.begin(), ans.end());
  for (vector<int> now : ans) {
    for (int x : now) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}