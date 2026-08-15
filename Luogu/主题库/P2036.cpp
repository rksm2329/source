#include<iostream>

using namespace std;

int n,mi = 1ll << 31, s[20],b[20];

void dfs(int t,int m1,int m2,bool f){ // t 为当前位置，m1,m2 为酸度、苦度，f 为标记
  if (t == n + 1){
    if (f){
      mi = min(mi,abs(m1 - m2));
    }
    return;
  }
  dfs(t + 1,m1 * s[t],m2 + b[t],1); // (t,m1,m2,f) -> (t + 1,m1 * s[t],m2 * b[t]),(t + 1,m1,m2,f)
  dfs(t + 1,m1,m2,f);
}

int main(){
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> s[i] >> b[i];
  }
  dfs(1,1,0,0);
  cout << mi;
  return 0;
}