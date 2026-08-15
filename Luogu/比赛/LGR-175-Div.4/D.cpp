#include <bits/stdc++.h>

using namespace std;

int k;

int main() {
  cin >> k;
  bool haveAns = 0;
  for (int a = 1; a <= 9; a++) {
    for (int b = 0; b <= 9; b++) {
      for (int c = 0; c <= 9; c++) {
        if ((a * 10 + b) % k == 0 && (b * 10 + c) % k == 0 && (a * 100 + b * 10 + c) % k == 0) {
          cout << a << b << c << '\n';
          haveAns = 1;
        }
      }
    }
  }
  if (!haveAns) {
    cout << "None!";
  }
  return 0;
}