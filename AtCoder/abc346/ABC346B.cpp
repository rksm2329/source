#include <bits/stdc++.h>

using namespace std;

const string p = "wbwbwwbwbwbw";

int main() {
  int w, b;
  cin >> w >> b;
  for (int i = 0; i < p.size(); i++) {
    int nw = 0, nb = 0;
    for (int j = 0; j < w + b; j++) {
      nw += p[(i + j) % p.size()] == 'w';
      nb += !(p[(i + j) % p.size()] == 'w');
    }
    if (nw == w && nb == b) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}