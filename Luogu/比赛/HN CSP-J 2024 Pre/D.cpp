#include <bits/stdc++.h>

using namespace std;

int t;
long long ans;
string s;

bool C() {
  string t = "";
  int cnt = 1;
  t = s[1];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      t += s[i];
    } else {
      cnt++;
      t = s[i];
    }
  }
  return cnt == 2;
}

void dfs(long long cnt) {
  if (C()) {
    ans = min(ans, cnt);
    return;
  }
  for (int i = 0; i < s.size(); i++) {
    if (!i) {
      swap(s[i], s[s.size() - 1]);
      dfs(cnt + 1);
      swap(s[i], s[s.size() - 1]);
      swap(s[i], s[i + 1]);
      dfs(cnt + 1);
      swap(s[i], s[i + 1]);
    } else if (i == s.size() - 1) {
      swap(s[i], s[0]);
      dfs(cnt + 1);
      swap(s[i], s[0]);
      swap(s[i], s[i - 1]);
      dfs(cnt + 1);
      swap(s[i], s[i - 1]);
    } else {
      swap(s[i], s[i - 1]);
      dfs(cnt + 1);
      swap(s[i], s[i - 1]);
      swap(s[i], s[i + 1]);
      dfs(cnt + 1);
      swap(s[i], s[i + 1]);
    }
  }
}

void Solve() {
  cin >> s;
  ans = LLONG_MAX;
  dfs(0);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}