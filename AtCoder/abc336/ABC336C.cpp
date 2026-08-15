#include <bits/stdc++.h>

using namespace std;

long long n, a[70], tot;

int main() {
  cin >> n;
  n--;
  if (!n) {
    cout << 0;
    return 0;
  }
  for (; n; n /= 5) {
    a[++tot] = n % 5;
  }
  for (int i = tot; i; i--) {
    cout << a[i] * 2;
  }
  return 0;
}