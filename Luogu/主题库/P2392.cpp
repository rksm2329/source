#include<iostream>
#include<climits>

using namespace std;

int ans,sum,s[10],kkk[10][30];

void dfs(int id,int x,int Time_a,int Time_b) { // id 为当前学科编号，x 为当前的题目，Time_a,Time_b 为左边脑子和右边脑子的运算时间
  if (x == s[id] + 1){
    ans = min(ans,max(Time_a,Time_b));
    return;
  }
  dfs(id,x + 1,Time_a + kkk[id][x],Time_b),dfs(id,x + 1,Time_a,Time_b + kkk[id][x]); // (id,x,Time_a,Time_b)->(id,x + 1,Time_a + kkk[id][x],Time_b),(id,x + 1,Time_a,Time_b + kkk[id][x])
}

int main(){
  for (int i = 1; i <= 4; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= s[i]; j++) {
      cin >> kkk[i][j];
    }
    ans = INT_MAX;
    dfs(i,1,0,0);
    sum += ans;
  }
  cout << sum;
  return 0;
}