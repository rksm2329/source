#include <bits/stdc++.h>

using namespace std;

char a, b, c;
int ind[5];
vector<int> g[5];

int main() {
  cin >> a >> b >> c;
  if (a == '<') {
    g[1].push_back(2);
    ind[2]++;
  } else {
    g[2].push_back(1);
    ind[1]++;
  }
  if (b == '<') {
    g[1].push_back(3);
    ind[3]++;
  } else {
    g[3].push_back(1);
    ind[1]++;
  }
  if (c == '<') {
    g[2].push_back(3);
    ind[3]++;
  } else {
    g[3].push_back(2);
    ind[2]++;
  }
  queue<int> q;
  for (int i = 1; i <= 3; i++) {
    if (!ind[i]) {
      q.push(i);
    }
  }
  vector<int> ans;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    ans.push_back(x);
    for (int y : g[x]) {
      ind[y]--;
      if (!ind[y]) {
        q.push(y);
      }
    }
  }
  cout << char(ans[1] - 1 + 'A');
  return 0;
}