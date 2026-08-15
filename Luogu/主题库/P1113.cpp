#include <cstdio>
#include <iostream>

using namespace std;

int n, l, t, ans[10005], maxans;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> i;
    cin >> l;
    int tmp = 0;
    while (scanf("%d", &t) && t) {
      tmp = max(ans[t], tmp);
    }
    ans[i] = tmp + l;
    maxans = max(ans[i], maxans);
  }
  cout << maxans;
  return 0;
}
