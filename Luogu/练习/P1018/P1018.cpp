#include <bits/stdc++.h>

using namespace std;

int n, k, a[51000];
char s[51000];

struct node {
  int v, c[500];
  bool exi;
} cut[500][100], ans[500];

node culc(int l, int r) {
  node e;
  e.v = r - l + 1, e.exi = 1;
  for (int i = 1; i <= e.v; i++) {
    e.c[i] = a[r - i + 1];
  }
  return e;
}

node mul(node e1, node e2) {
  node emul;
  emul.exi = 1, emul.v = e1.v + e2.v - 1;
  for (int i = 1; i <= emul.v; i++) {
    emul.c[i] = 0;
  }
  for (int i = 1; i <= e1.v; i++) {
    for (int j = 1; j <= e2.v; j++) {
      emul.c[i + j - 1] += e1.c[i] * e2.c[j];
    }
  }
  int q = 0;
  for (int i = 1; i <= emul.v; i++) {
    emul.c[i] += q;
    q = emul.c[i] / 10;
    emul.c[i] %= 10;
  }
  for (; q; q /= 10) {
    emul.c[++emul.v] = q % 10;
  }
  return emul;
}

node Max(node e1, node e2) {
  if (!e1.exi || e1.v < e2.v) {
    return e2;
  }
  if (!e2.exi || e2.v < e1.v) {
    return e1;
  }
  for (int i = e1.v; i >= 1; i--) {
    if (e1.c[i] > e2.c[i]) {
      return e1;
    } else if (e2.c[i] > e1.c[i]) {
      return e2;
    }
  }
  return e1;
}

int main() {
  cin >> n >> k >> s;
  for (int i = 0; i < n; i++) {
    a[i + 1] = s[i] - '0';
  }
  for (int i = 1; i <= n; i++) {
    ans[i].exi = false;
    for (int j = 1; j <= k; j++) {
      cut[i][j].exi = 0;
    }
  }
  for (int i = 1; i < n; i++) {
    cut[i][1] = culc(1, i);
    for (int j = 2; j <= k; j++) {
      for (int fr = j - 1; fr < i; fr++) {
        if (cut[fr][j - 1].exi) {
          cut[i][j] = Max(cut[i][j], mul(cut[fr][j - 1], culc(fr + 1, i)));
        }
      }
    }
    if (cut[i][k].exi) {
      ans[i] = mul(cut[i][k], culc(i + 1, n));
    }
  }
  node lastans;
  lastans.exi = 0;
  for (int i = 1; i < n; i++) {
    node tmp = Max(ans[i], lastans);
    lastans = tmp;
  }
  bool f = 0;
  for (int i = 1; i <= lastans.v; i++) {
    if (lastans.c[i]) {
      f = 1;
      break;
    }
  }
  if (!f) {
    cout << 0;
    return 0;
  }
  for (int i = lastans.v; i >= 1; i--) {
    cout << lastans.c[i];
  }
  return 0;
}