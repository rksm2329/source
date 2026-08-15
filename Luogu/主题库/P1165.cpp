#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n;
int op,x;
int top;
int stk[MAXN];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0),cout.tie(0);
  cin >> n;
  while (n--){
    cin >> op;
    if (op == 0){
      cin >> x;
      top++;
      stk[top] = max(stk[top - 1],x);
    }
    else if (op == 1){
      top -= (top != 0);
    }
    else {
      cout << stk[top] << '\n';
    }
  }
  return 0;
}