#include<iostream>

using namespace std;

int n,a[10];

void dfs(int x,int y,int last){
  if (y == n){
    for (int i = 1; i <= x; i++){
      cout << a[i];
      if (i != x){
        cout << '+';
      }
    }
    cout << '\n';
    return;
  }
  if (y > n){
    return;
  }
  for (int i = last; i < n; i++){
    a[x + 1] = i;
    dfs(x + 1,y + i,i);
  }
}

int main(){
  cin >> n;
  dfs(0,0,1);
  return 0;
}