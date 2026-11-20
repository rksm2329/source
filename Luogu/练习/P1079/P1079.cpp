#include <iostream>

using namespace std;

string k, s;

int main() {
  cin >> k >> s;
  int index = 0, l = k.size();
  if (k.size() > s.size()) {
    k.resize(s.size());
  }
  while (k.size() < s.size()) {
    k += k[index];
    index = (index + 1) % l;
  }
  for (int i = 0; i < s.size(); i++) {
    if (k[i] >= 'A' && k[i] <= 'Z') {
      int t;
      if (s[i] >= 'A' && s[i] <= 'Z') {
        t = (s[i] - 'A' - (k[i] - 'A') + 26) % 26;
        s[i] = char(t + 'A');
      } else {
        t = (s[i] - 'a' - (k[i] - 'A') + 26) % 26;
        s[i] = char(t + 'a');
      }
    } else {
      int t;
      if (s[i] >= 'A' && s[i] <= 'Z') {
        t = (s[i] - 'A' - (k[i] - 'a') + 26) % 26;
        s[i] = char(t + 'A');
      } else {
        t = (s[i] - 'a' - (k[i] - 'a') + 26) % 26;
        s[i] = char(t + 'a');
      }
    }
  }
  cout << s;
  return 0;
}