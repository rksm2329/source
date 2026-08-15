#include <bits/stdc++.h>

using namespace std;

const int MAXN = 160;

int n;
string s[MAXN];
string ans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      cnt += (s[j][0] == s[i][0]);
    }
    if (cnt >= 5 && ans.find(s[i][0]) == string::npos) {
      ans += s[i][0];
    }
  }
  if (!ans.size()) {
    cout << "PREDAJA";
    return 0;
  }
  sort(ans.begin(), ans.end());
  cout << ans;
  return 0;
}