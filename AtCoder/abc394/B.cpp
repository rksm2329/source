#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string s[55];
int n;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  sort(s + 1, s + n + 1, [](const string &i, const string &j) {
    return i.size() < j.size();
  });
  for (int i = 1; i <= n; i++) {
    cout << s[i];
  }
  return 0;
}