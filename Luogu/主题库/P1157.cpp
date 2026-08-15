// O(r * C(n, r))
#include<iostream>
#include<iomanip>

using namespace std;

int n,r,a[30]; // 状态：当前序列，转移：把比上一个数大的数加入序列里面

void dfs(int x,int last){

  if (x == r + 1){

    for (int i = 1; i <= r; i++){

      cout << setw(3) << a[i];
    }

    cout << '\n';

    return;
  }

  for (int i = last + 1; i <= n; i++){

    a[x] = i;

    dfs(x + 1,i);
  }
}

int main(){

  cin >> n >> r;

  dfs(1,0);

  return 0;
}