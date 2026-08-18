#include <bits/stdc++.h>

using namespace std;

int n, num;
long long ans, a[8][7];
char c;

int f(char ch) {
  switch (ch) {
    case 'B': {
      return 1;
    } case 'E': {
      return 2;
    } case 'S': {
      return 3;
    } case 'I': {
      return 4;
    } case 'G': {
      return 5;
    } case 'O': {
      return 6;
    } default: {
      return 7;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c >> num;
    a[f(c)][(num % 7 + 7) % 7]++;
  }
  for (int b = 0; b < 7; b++) {
    for (int e = 0; e < 7; e++) {
      for (int s = 0; s < 7; s++) {
        for (int i = 0; i < 7; i++) {
          for (int g = 0; g < 7; g++) {
            for (int o = 0; o < 7; o++) {
              for (int m = 0; m < 7; m++) {
                int answ = (b + e + s + s + i + e) * (g + o + e + s) * (m + o + o);
                if (answ % 7 == 0) {
                  ans += a[1][b] * a[2][e] * a[3][s] * a[4][i] * a[5][g] * a[6][o] * a[7][m];
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}