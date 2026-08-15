#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 2e5 + 10;

string s;
int stk[MAXN][3], top[3];
stack<char> st;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      st.push('(');
      stk[++top[0]][0] = i;
    } else if (s[i] == '[') {
      st.push('[');
      stk[++top[1]][1] = i;
    } else if (s[i] == '<') {
      st.push('<');
      stk[++top[2]][2] = i;
    } else if (s[i] == ')') {
      if (!top[0] || st.top() != '(') {
        cout << "No";
        return 0;
      }
      --top[0], st.pop();
    } else if (s[i] == ']') {
      if (!top[1] || st.top() != '[') {
        cout << "No";
        return 0;
      }
      --top[1], st.pop();
    } else {
      if (!top[2] || st.top() != '<') {
        cout << "No";
        return 0;
      }
      --top[2], st.pop();
    }
  }
  cout << (top[0] || top[1] || top[2] || !st.empty() ? "No" : "Yes");
  return 0;
}