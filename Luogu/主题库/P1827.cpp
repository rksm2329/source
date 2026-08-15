#include <bits/stdc++.h>

using namespace std;

string s, t, ans;

void dfs(int x, int y, int p, int q) {
  if (x > y || p > q) {
    return;
  }
  dfs(x + 1, x + s.find(t[x]) - p, p, s.find(t[x]) - 1);
  dfs(x + s.find(t[x]) - p + 1, y, s.find(t[x]) + 1, q); 
  cout << t[x];
}

int main() {
  cin >> s >> t;
  dfs(0, s.size() - 1, 0, s.size() - 1);
  return 0;
}