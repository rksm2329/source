#include <bits/stdc++.h>

using namespace std;

int n, x;
int mp[12];

int main() {
  mp[2] = mp[3] = mp[4] = mp[5] = mp[6] = mp[7] = mp[8] = mp[9] = mp[11] = 4;
  mp[10] = 12;
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    sum += x;
    mp[x]--;
  }
  if (sum > 21) {
    cout << "DOSTA";
    return 0;
  }
  int ans = 0, sna = 0;
  for (int i = 2; i <= min(21 - sum, 11); i++) {
    ans += mp[i];
  }
  for (int i = 21 - sum + 1; i <= 11; i++) {
    sna += mp[i];
  }
  cout << (sna >= ans ? "DOSTA" : "VUCI");
  return 0;
}