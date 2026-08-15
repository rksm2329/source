// O(n*n!),O(n^2)
#include <iostream>
#include <vector>

using namespace std;

int n, t, m, ans, kkk[50][50];

vector<int> d[50];

bool check(int index, int x){
  for (int i = 0; i < d[index].size(); i++){
    if (kkk[d[index][i]][x] == 1){
      return 0;
    }
  }
  return 1;
}

void dfs(int x, int bj){
  if (bj > t){
    return;
  }
  if (x > n){
    if (bj == t){
      ans++;
    }
    return;
  }
  for (int i = 1; i <= bj; i++){
    if (check(i, x)){
      d[i].push_back(x);
      dfs(x + 1, bj);
      d[i].pop_back();
    }
  }
  d[bj + 1].push_back(x);
  dfs(x + 1, bj + 1);
  d[bj + 1].pop_back();
}

int main(){
  cin >> n >> t >> m;
  for (int i = 1; i <= m; i++){
    int a, b;
    cin >> a >> b;
    kkk[a][b] = kkk[b][a] = 1;
  }
  dfs(1,0);
  cout << ans;
  return 0;
}