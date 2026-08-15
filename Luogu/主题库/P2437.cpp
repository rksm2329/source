#include<iostream>
using namespace std;
const int MAXN = 1e5 + 10;
struct bigint{
  int len,num[MAXN] = {0};
  int &operator [] (int i){
    return num[i];
  }
}a,b,ans;

int n,m;

bigint operator + (const bigint &a,const bigint &b){
  bigint c;
  c.len = max(a.len,b.len) + 1;
  for (int i = 0; i < c.len; i++){
    c[i] = a.num[i] + b.num[i];
  }
  for (int i = 0; i < c.len - 1; i++){
    c[i + 1] += c[i] / 10,c[i] %= 10;
  }
  for (; c.len > 1 && !c[c.len - 1]; c.len--){
  }
  return c;
}

void output(){
  for (int i = ans.len - 1; i >= 0; i--){
    cout << ans[i];
  }
}

int main(){
  cin >> m >> n;
  a.len = 1,a[0] = 1,b.len = 1,b[0] = 1;
  for (int i = 3; i <= n - m + 1; i++){
    ans = a + b;
    a = b,b = ans;
  }
  output();
  return 0;
}