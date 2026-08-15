#include <bits/stdc++.h>

using namespace std;

struct Node {
  int x, y, z;
} a[4];

bool f(int l1, int r1, int l2, int r2) {
  return !(r1 <= l2 || r2 <= l1);
}

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> a[i].x >> a[i].y >> a[i].z;
  }
  if (f(a[0].x, a[1].x, a[2].x, a[3].x) && f(a[0].y, a[1].y, a[2].y, a[3].y) && f(a[0].z, a[1].z, a[2].z, a[3].z)) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}