#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[8];
vector<int> v;

void dfs(int x, int cnt) {
  if (cnt == 5) {
    vector<int> k = v;
    sort(k.begin(), k.end());
    if (k[0] == k[1] && k[3] == k[4] && (k[1] == k[2] || k[2] == k[3]) && k[0] != k[4]) {
      cout << "Yes";
      exit(0);
    }
    return;
  }
  if (x == 8) {
    return;
  }
  v.push_back(a[x]);
  dfs(x + 1, cnt + 1);
  v.pop_back();
  dfs(x + 1, cnt);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  for (int i = 1; i <= 7; i++) {
    cin >> a[i];
  }
  dfs(1, 0);
  cout << "No";
  return 0;
}