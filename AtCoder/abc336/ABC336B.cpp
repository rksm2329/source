#include <bits/stdc++.h>

using namespace std;

int lowbit(int x) {
  return x & (-x);
}

int n;

int main() {
  cin >> n;
  cout << log2(lowbit(n));
  return 0;
}