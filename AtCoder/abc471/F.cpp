#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using psi = pair<string, int>;

const int MAXN = 1e5 + 10;

struct Compare1 {
  bool operator()(const string &i, const string &j) const {
    return i.size() != j.size() ? i.size() > j.size() : i > j;
  }
};

struct Compare2 {
  bool operator()(const psi &i, const psi &j) const {
    return i.first.size() != j.first.size() ? i.first.size() > j.first.size() : i.first > j.first;
  }
};

int n, k;
string s[MAXN];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  return 0;
}