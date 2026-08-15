#include<bits/stdc++.h>

using namespace std;

int k,m,n,a,b;
bool flag;

int main(){
  cin >> k >> m >> n;
  for (int i = 1; i <= m; i++){
    cin >> a >> b;
    if (!a && b > 0){
      cout << i << ' ';
      flag = 1;
      continue;
    }
    if (!b){
      continue;
    }
    if (k / a * b >= n){
      cout << i << ' ';
      flag = 1;
    }
  }
  if (!flag){
    cout << -1;
  }
  return 0;
}