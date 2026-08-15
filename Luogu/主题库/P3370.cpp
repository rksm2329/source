#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10, MOD = 233333, base = 261;

int n, ans;
string s;
vector<string> linker[MOD + 10];

void insert() {
  int hash = 1;
  for (int i = 0; i < s.size(); i++) {
    hash = (hash * 1ll * base + s[i]) % MOD;
  }
  string t = s;
  for (int i = 0; i < linker[hash].size(); i++) {
    if (linker[hash][i] == t) {
      return;
    }
  }
  linker[hash].push_back(t);
  ans++;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    insert();
  }
  cout << ans;
  return 0;
}