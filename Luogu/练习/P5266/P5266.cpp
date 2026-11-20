#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mp;
int n, op, score;
string name;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> op;
    switch (op) {
      case 1: {
        cin >> name >> score;
        mp[name] = score;
        cout << "OK\n";
        break;
      } case 2: {
        cin >> name;
        if (mp.count(name)) {
          cout << mp[name] << '\n';
        } else {
          cout << "Not found\n";
        }
        break;
      } case 3: {
        cin >> name;
        if (mp.count(name)) {
          mp.erase(name);
          cout << "Deleted successfully\n";
        } else {
          cout << "Not found\n";
        }
        break;
      } case 4: {
        cout << mp.size() << '\n';
      }
    }
  }
  return 0;
}