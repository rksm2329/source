#include <bits/stdc++.h>

using namespace std;

char s[4][5][5], sp[4][5][5], pt[4][5][5], t[5][5];
int vis[5][5], t1[4], t2[4];

// 旋转矩阵
void swp(int index) {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      t[i][j] = sp[index][i][j];
    }
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      sp[index][i][j] = t[4 - j + 1][i];
    }
  }
}

// 平移矩阵
bool py(int index, int x, int y) {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (sp[index][i][j] == '#' &&
          (x + i > 4 || y + j > 4 || x + i < 1 || y + j < 1)) {
        return false;
      }
    }
  }
  return true;
}

// 检查矩阵
bool check() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (vis[i][j] != 1) {
        return false;
      }
    }
  }
  return true;
}

// 求最后的分布情况
void ok() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      vis[i][j] = 0;
    }
  }
  for (int id = 1; id <= 3; id++) {
    for (int x = 1; x <= 4; x++) {
      for (int y = 1; y <= 4; y++) {
        vis[x + t1[id]][y + t2[id]] += pt[id][x][y] == '#';
      }
    }
  }
}

// dfs 搜索
void dfs(int x) {
  if (x > 3) {
    ok();
    if (check()) {
      cout << "Yes";
      exit(0);
    }
    return;
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      sp[x][i][j] = s[x][i][j];
    }
  }
  for (int scnt = 1; scnt <= 4; scnt++) {       // 枚举旋转次数
    for (int pyl1 = -4; pyl1 <= 4; pyl1++) {    // 行偏移量
      for (int pyl2 = -4; pyl2 <= 4; pyl2++) {  // 列偏移量
        if (py(x, pyl1, pyl2)) {
          for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
              pt[x][i][j] = sp[x][i][j];
            }
          }
          t1[x] = pyl1, t2[x] = pyl2;
          dfs(x + 1);
        }
      }
    }
    swp(x);
  }
}

int main() {
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= 4; k++) {
        cin >> s[i][j][k];
      }
    }
  }
  dfs(1);
  cout << "No";
  return 0;
}