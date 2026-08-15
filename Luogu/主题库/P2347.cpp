#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e3 + 10;
const int w[] = {1, 2, 3, 5, 10, 20};

int a[6];
bitset<MAXV> s;

int main() {
  for (int i = 0; i < 6; i++) {
    cin >> a[i];
  }
  s[0] = 1;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < a[i]; j++) {
      s |= s << w[i];
    }
  }
  cout << "Total=" << s.count() - 1;
  return 0;
}