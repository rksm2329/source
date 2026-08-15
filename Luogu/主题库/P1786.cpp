#include <bits/stdc++.h>

using namespace std;

const int MAXN = 120;

struct Node {
  string name, zw, nzw;
  long long bg;
  int lv, id;
} a[MAXN];

int n;

bool cmp(const Node &i, const Node &j) {
  if (i.bg == j.bg) {
    return i.id < j.id;
  }
  return i.bg > j.bg;
}

int id(string s) {
  if (s == "BangZhu") {
    return 1;
  } else if (s == "FuBangZhu") {
    return 2;
  } else if (s == "HuFa") {
    return 3;
  } else if (s == "ZhangLao") {
    return 4;
  } else if (s == "TangZhu") {
    return 5;
  } else if (s == "JingYing") {
    return 6;
  } else {
    return 7;
  }
}

bool cmp2(const Node &i, const Node &j) {
  if (id(i.nzw) == id(j.nzw)) {
    if (i.lv == j.lv) {
      return i.id < j.id;
    }
    return i.lv > j.lv;
  }
  return id(i.nzw) < id(j.nzw);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].name >> a[i].zw >> a[i].bg >> a[i].lv;
    a[i].id = i;
  }
  sort(a + 4, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {  
    if (i == 1) {
      a[i].nzw = "BangZhu";
    } else if (i >= 2 && i <= 3) {
      a[i].nzw = "FuBangZhu";
    } else if (i >= 4 && i <= 5) {
      a[i].nzw = "HuFa";
    } else if (i >= 6 && i <= 9) {
      a[i].nzw = "ZhangLao";
    } else if (i >= 10 && i <= 16) {
      a[i].nzw = "TangZhu";
    } else if (i >= 17 && i <= 41) {
      a[i].nzw = "JingYing";
    } else {
      a[i].nzw = "BangZhong";
    }
  }
  sort(a + 1, a + n + 1, cmp2);
  for (int i = 1; i <= n; i++) {
    cout << a[i].name << ' ' << a[i].nzw << ' ' << a[i].lv << '\n';
  }
  return 0;
}