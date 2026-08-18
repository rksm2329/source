#include <bits/stdc++.h>

using namespace std;

struct node {
  int id, ti, rt, pr;
  bool operator<(const node &other) const {
    return (pr != other.pr ? pr < other.pr : ti > other.ti);
  }
} now;

priority_queue<node> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long sum = 0;
  while (cin >> now.id >> now.ti >> now.rt >> now.pr) {
    while (!pq.empty() && sum + pq.top().rt <= now.ti) {
      node tmp = pq.top();
      pq.pop();
      sum += tmp.rt;
      cout << tmp.id << ' ' << sum << '\n';
    }
    if (!pq.empty()) {
      node tmp = pq.top();
			pq.pop();
			tmp.rt = tmp.rt - now.ti + sum;
			pq.push(tmp);
    }
    pq.push(now);
    sum = now.ti;
  }
  while (!pq.empty()) {
    node tmp = pq.top();
    pq.pop();
    sum += tmp.rt;
    cout << tmp.id << ' ' << sum << '\n';
  }
  return 0;
}