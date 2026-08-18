#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4 + 10;

struct node {
  int p, c;
} a[MAXN];

struct pii {
  int x, id;
  bool operator<(const pii &other) const {
    return (x != other.x ? x > other.x : id > other.id);
  }
};

int n, k;
long long m;
priority_queue<pii> pq1, pq2, pq3;

bool cmp(const node &i, const node &j) {
  return i.c < j.c;
}

void chk(int id1, int id2, int t1, int t2) {
  if (pq1.empty()) {
    if (id1 == id2) {
      pq2.pop();
    }
    pq3.pop();
  } else {
    if (t1 >= t2) {
      if (id1 == id2) {
        pq2.pop();
      }
      pq3.pop();
    } else {
      if (id1 == id2) {
        pq3.pop();
      }
      pq1.pop(), pq2.pop();
    }
  }
}

int main() {
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].p >> a[i].c;
  }
  sort(a + 1, a + n + 1, cmp);
  long long sum = 0;
  for (int i = 1; i <= k; i++) {
    sum += a[i].c;
    pq1.push({a[i].p - a[i].c, i});
    if (sum > m) {
      cout << i - 1;
      return 0;
    }
  }
  for (int i = k + 1; i <= n; i++) {
    pq2.push({a[i].c, i}); pq3.push({a[i].p, i});
  }
  for (int i = k + 1; i <= n; i++) {
    int id1 = pq2.top().id, id2 = pq3.top().id;
    int t1 = 0, t2 = pq3.top().x;
    if (!pq1.empty()) {
      t1 = pq1.top().x + pq2.top().x;
      sum += min(t1, t2);
    } else {
      sum += t2;
    }
    if (sum > m) {
      cout << i - 1;
      return 0;
    }
    chk(id1, id2, t1, t2);
  }
  cout << n;
  return 0;
}