#include <bits/stdc++.h>

using namespace std;

int t, ot, a[10][10];
bool line[10][10], col[10][10], vis[10][10];
bool flag;

void PrintSudoku() {
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  flag = 1;
}

void dfs(int x, int y) {
  if (a[x][y]) {
    if (x == 9 && y == 9) {
      PrintSudoku();
    } else if (y == 9) {
      dfs(x + 1, 1);
    } else {
      dfs(x, y + 1);
    }
    return;
  }
  for (int i = 1; i <= 9; i++) {
    if (!(line[x][i]) && !(col[y][i]) && !(vis[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i])) {
      line[x][i] = col[y][i] = vis[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = 1;
      a[x][y] = i;
      if (x == 9 && y == 9) {
        PrintSudoku();
      } else if (y == 9) {
        dfs(x + 1, 1);
      } else {
        dfs(x, y + 1);
      }
      a[x][y] = 0;
      line[x][i] = col[y][i] = vis[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = 0;
    }
    if (flag) {
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      cin >> a[i][j];
      line[i][a[i][j]] = col[j][a[i][j]] = vis[(i - 1) / 3 * 3 + (j - 1) / 3 + 1][a[i][j]] = 1;
    }
  }
  dfs(1, 1);
  return 0;
}