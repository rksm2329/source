#include <iostream>

using namespace std;

int n, ans, a[20];

bool used1[20], used2[20], used3[20];

void Print() {
  for (int i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

void dfs(int x) {
  if (x == 1 + n) {
    ans++;
    if (ans <= 3) {
      Print();
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (!used1[i] && !used2[x - i + n] && !used3[x + i]) {
      used1[i] = used2[x - i + n] = used3[x + i] = 1;
      a[x] = i;
      dfs(x + 1);
      used1[i] = used2[x - i + n] = used3[x + i] = 0;
    }
  }
}

int main() {
  cin >> n;
  dfs(1);
  cout << ans;
  return 0;
}