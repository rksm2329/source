#include <cstring>
#include <iostream>


using namespace std;

const int MAXN = 1e3 + 10;

int n, l;
char s[MAXN], t[MAXN];

void add() {
  for (int i = 0; i < l; i++) {
    t[l - i - 1] = s[i];
  }
  l += 2;
  for (int i = 0; i < l; i++) {
    s[i] += t[i];
    if (s[i] >= n) {
      s[i + 1]++, s[i] -= n;
    }
  }
  while (!s[l - 1]) {
    l--;
  }
}

bool check() {
  for (int i = 0; i < l; i++) {
    if (s[i] != s[l - i - 1]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n >> s;
  l = strlen(s);
  for (int i = 0; i < l; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      s[i] -= '0';
    } else {
      s[i] = s[i] - 'A' + 10;
    }
  }
  int step = 0;
  while (!check()) {
    step++;
    if (step > 30) {
      cout << "Impossible!";
      return 0;
    }
    add();
  }
  cout << "STEP=" << step;
  return 0;
}