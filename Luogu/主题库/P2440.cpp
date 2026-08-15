#include<iostream>

using namespace std;

const int MAXN = 1e5 + 10,MAXL = 1e8 + 10;

int n,k,a[MAXN];

bool j(int x){
  int sum = 0;
  for (int i = 1; i <= n; i++){
    sum += a[i] / x;
  }
  return sum >= k;
}

int f(){
  int l = 0,r = MAXL;
  while (l < r){
    int mid = (l + r + 1) >> 1;
    j(mid) ? l = mid : r = mid - 1;
  }
  return l;
}

int main(){
  cin >> n >> k;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  cout << f();
  return 0;
}