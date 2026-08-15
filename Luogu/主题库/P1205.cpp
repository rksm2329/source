#include <iostream>

using namespace std;

int n;
char s[20][20], t[20][20], b[20][20], c[20][20];

void Swap() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][j] = s[n - j + 1][i];
    }
  }
}
void Swap2() {
  for (int i = 1; i <= n; i++) {
    for (int j1 = 1, j2 = n; j1 <= j2; j1++, j2--) {
      swap(s[j1][i], s[j2][i]);
      b[j1][i] = s[j1][i], b[j2][i] = s[j2][i];
    }
  }
}

void Return(char s[20][20], char b[20][20]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = b[i][j];
    }
  }
}

bool Check() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (b[i][j] != t[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

void Input() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
      c[i][j] = s[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> t[i][j];
    }
  }
}

int main() {
  Input();
  Swap();
  if (Check()) {
    cout << 1;
    return 0;
  }
  Return(s, b);
  Swap();
  if (Check()) {
    cout << 2;
    return 0;
  }
  Return(s, b);
  Swap();
  if (Check()) {
    cout << 3;
    return 0;
  }
  Swap2();
  if (Check()) {
    cout << 4;
    return 0;
  }
  Swap();
  if (Check()) {
    cout << 5;
    return 0;
  }
  Return(s, b);
  Swap();
  if (Check()) {
    cout << 5;
    return 0;
  }
  Return(s, b);
  Swap();
  if (Check()) {
    cout << 5;
    return 0;
  }
  Return(b, c);
  if (Check()) {
    cout << 6;
    return 0;
  }
  cout << 7;
  return 0;
}