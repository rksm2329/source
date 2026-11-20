#include <climits>
#include <cstring>
#include <iostream>


using namespace std;

const int MAXN = 1e5 + 3;

int n, t, H[MAXN], F[MAXN];

int main() {
  while (cin >> H[++n])
    ;
  n--;
  t = 0, memset(F, 0, sizeof(F)), F[0] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = t + 1;
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      (F[m] < H[i] ? l = m : r = m);
    }
    int x = l + 1;
    if (x > t)
      t = x;
    F[x] = H[i];
  }
  cout << t << '\n';
  t = 0, memset(F, 0, sizeof(F)), F[0] = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = t + 1;
    while (r - l > 1) {
      int m = l + (r - l) / 2;
      (F[m] < H[i] ? l = m : r = m);
    }
    int x = l + 1;
    if (x > t)
      t = x;
    ;
    F[x] = H[i];
  }
  cout << t << '\n';
  return 0;
}