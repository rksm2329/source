  #include <bits/stdc++.h>

  using namespace std;

  int t, id, n;
  long long k;
  string s;

  void Solve() {
    cin >> n >> k >> s;
    k = min(k, 2ll);
    if (!k || n <= 2) {
      cout << s << '\n';
      return;
    }
    string ans;
    ans = s[0];
    for (int i = 0; i < n - 2; i++) {
      if (s[i] != s[i + 2]) {
        ans += s[i + 1];
      }
    }
    if (n > 1) {
      ans += s[n - 1];
    }
    if (k == 1) {
      cout << ans << '\n';
    } else {
      cout << ans[0];
      for (int i = 0; i < ans.size() - 2; i++) {
        if (ans[i] != ans[i + 2]) {
          cout << ans[i + 1];
        }
      }
      if (ans.size() > 1) {
        cout << ans[ans.size() - 1];
      }
      cout << '\n';
    }
  }

  int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    for (cin >> t >> id; t--; Solve()) {
    }
    return 0;
  }