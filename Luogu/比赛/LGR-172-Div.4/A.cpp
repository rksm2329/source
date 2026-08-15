#include <bits/stdc++.h>

using namespace std;

int a[3], ans = INT_MAX;
int aZ, ayz;

int main() {
  cin >> a[0] >> a[1] >> a[2];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        int Z = a[i] + a[j];
        int yz = a[3 - i - j];
        if (Z >= yz) {
          if (Z - yz < ans) {
            ans = Z - yz;
            aZ = Z, ayz = yz;
          }
        }
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i != j) {
        int yz = a[i] + a[j];
        int Z = a[3 - i - j];
        if (Z >= yz) {
          if (Z - yz < ans) {
            ans = Z - yz;
            aZ = Z, ayz = yz;
          }
        }
      }
    }
  }
  cout << aZ << ' ' << ayz;
  return 0;
}