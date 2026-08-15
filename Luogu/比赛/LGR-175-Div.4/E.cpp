#include <bits/stdc++.h>

using namespace std;

int t;

void Solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  int cnt0 = 0, lstcnt0 = 0, cnt1 = 0;
  bool lstisf = 1;
  bool flag = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != '1') {
      flag = 0;
      break;
    }
  }
  if (flag) {
    cout << "Yes\n";
    return;
  }
  for (int i = 0; i < s.size(); i++) {
    if (i && s[i] == '1' && s[i - 1] == '1') {
      cout << "No\n";
      return;
    }
    if (s[i] == '0') {
      cnt0++;
      cnt1 = 0;
    } else if (s[i] == '1') {
      cnt1++;
      if (cnt0 > n) {
        cout << "No\n";
        return;
      }
      if (lstcnt0) {
        if (cnt0 != lstcnt0) {
          if (!((lstcnt0 < cnt0 && lstisf && s[0] == '0') || (i == s.size() - 1 && cnt0 < lstcnt0 && s[s.size() - 1] == '0'))) {
            cout << "No\n";
            return;
          }
          lstisf = 0;
        }
      }
      lstcnt0 = cnt0;
      cnt0 = 0;
    }
  }
  if (cnt0) {
    if (cnt0 > n) {
      cout << "No\n";
      return;
    }
    if (lstcnt0 && cnt0 > lstcnt0 && !lstisf) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (cin >> t; t--; Solve()) {
  }
  return 0;
}