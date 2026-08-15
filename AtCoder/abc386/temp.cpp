#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  freopen("1.txt", "w", stdout);
  cout << 1 << '\n';
  srand(time(nullptr));
  string s, t;
  int pos = rand() % 500001;
  if (pos == 0) {
    s += 'a';
  }
  for (int i = 1; i <= 500000; i++) {
    char c = (rand() % 26) + 'a';
    s += c, t += c;
    if (pos == i) {
      s += 'a';
    }
  }
  cout << s << '\n' << t;
  return 0;
}