#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 1e4 + 10;

int n, m, a[MAXN];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    next_permutation(a + 1, a + n + 1);
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  return 0;
}