#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> isl, isr, lin, lout, rin, rout, gl, gr;

void initialize(vector<int> p) {
  int n = p.size();
  isl.resize(n), isr.resize(n), gl.resize(n), gr.resize(n);
  for (int i = 0; i < n; i++) {
    int mx = p[i], mi = p[i];
    if (i) mx = max(mx, p[i - 1]), mi = min(mi, p[i - 1]);
    if (i < n - 1) mx = max(mx, p[i + 1]), mi = min(mi, p[i + 1]);
    isl[i] = !i ? -1 : (p[i - 1] == mx ? 1 : (p[i - 1] == mi ? 0 : -1));
    isr[i] = i == n - 1 ? -1 : (p[i + 1] == mx ? 1 : (p[i + 1] == mi ? 0 : -1));
    bool l = isl[i] != -1, r = isr[i] != -1;
    gl[i] = l & !r, gr[i] = r & !l;
  }
  lin.resize(n), lout.resize(n), rin.resize(n), rout.resize(n);
  for (int i = 0; i < n; i++) {
    lin[i] = gr[i] ? i : (!i ? -1 : lin[i - 1]);
    lout[i] = gl[i] ? i : (!i ? -1 : lout[i - 1]);
  }
  for (int i = n - 1; ~i; i--) {
    rin[i] = gl[i] ? i : (i == n - 1 ? n : rin[i + 1]);
    rout[i] = gr[i] ? i : (i == n - 1 ? n : rout[i + 1]);
  }
}

bool exists_program(vector<int> x) {
  int l = x.front(), r = x.back();
  if (lin[r] >= rin[l]) return 0;
  if (lin[r] <= l || rin[l] >= r) return 1;
  if (lin[l] > lout[l] || rin[r] < rout[r]) return 1;
  if (~isr[l] && ~isl[r] && isr[l] == isl[r]) return 1;
  return (l - lout[l] > r - lout[r] || rout[l] - l < rout[r] - r);
}

#ifndef ONLINE_JUDGE
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; cin >> p[i++]);
  initialize(p);
  for (int i = 1, k; i <= q; i++) {
    cin >> k;
    vector<int> x(k);
    for (int j = 0; j < k; cin >> x[j++]);
    cout << exists_program(x);
  }
  return 0;
}
#endif