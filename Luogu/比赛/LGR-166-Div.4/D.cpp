#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool check(int x) {
  if (x == 1) return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 1) return 0;
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    s = "";
    int cnt = 0;
    int op = i - 1;
    for (int j = 1; cnt != i * i; j++) {
      if (!check(j + op + 'A' + 1)) {
        s += ' ';
      } else {
        s += op + 'A';
        cnt++;
        op = (op + 1) % 26;
      }
    }
    cout << s << '\n';
  }
  return 0;
}