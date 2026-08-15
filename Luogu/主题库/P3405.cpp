#include <bits/stdc++.h>

using namespace std;

const int MOD = 233333;

int n;
string a, b;
long long ans;
vector <pair <int, int>> linker[MOD + 10];

int gethash(string a, string b) {
  return (a[0] - 'A') + (a[1] - 'A') * 26 + (b[0] - 'A') * 26 * 26 + (b[1] - 'A') * 26 * 26 * 26;
}

void insert(int x) {
  for (int i = 0; i < linker[x % MOD].size(); i++) {
    if (linker[x % MOD][i].first == x) {
      linker[x % MOD][i].second++;
      break ;
    }
  }
  linker[x % MOD].push_back(pair <int, int> (x, 1));
}

int find(int x) {
  for (int i = 0; i < linker[x % MOD].size(); i++) {
    if (linker[x % MOD][i].first == x) {
      return linker[x % MOD][i].second;
    }
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    a[2] = 0;
    if (a[0] != b[0] || a[1] != b[1]) {
      ans += find(gethash(b, a));
    }
    insert(gethash(a, b));
  }
  cout << ans;
  return 0;
}