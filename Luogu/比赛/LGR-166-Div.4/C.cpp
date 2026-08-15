#include <bits/stdc++.h>

using namespace std;

int a[10];
int cnt[5];

int main() {
  for (int i = 1; i <= 8; i++) {
    cin >> a[i];
    if (a[i] >= 41) cnt[1]++;
    if (a[i] >= 63) cnt[2]++;
    if (a[i] >= 118) cnt[3]++;
    if (a[i]) cnt[4]++;
  }
  cout << max({(cnt[4] >= 1) * 1, (cnt[1] >= 4) * 3, (cnt[2] >= 4) * 8, (cnt[3] >= 1) * 10});
  return 0;
}