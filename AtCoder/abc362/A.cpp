#include <bits/stdc++.h>

using namespace std;

int a[3];
string c;
map<string, vector<int>> mp;

int main() {
  mp["Red"] = {1, 2}, mp["Green"] = {0, 2}, mp["Blue"] = {0, 1};
  cin >> a[0] >> a[1] >> a[2] >> c;
  cout << min(a[mp[c][0]], a[mp[c][1]]);
  return 0;
}