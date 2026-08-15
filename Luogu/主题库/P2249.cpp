#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int n,m,x,a[MAXN];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    cin >> x;
    int t = lower_bound(a + 1,a + n + 1,x) - a;
    if (a[t] == x){
      cout << t << ' ';
    } else {
      cout << -1 << ' ';
    }
  }
  return 0;
}