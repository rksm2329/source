#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1023;

int k,total;
long long ans[MAXN];

void dfs(int x,long long num){
    if (x > 10){
        return;
    }
    ans[++total] = num;
    for (int i = 0; i < num % 10; i++){
        dfs(x + 1,num * 10 + i);
    }
}

int main(){
    cin >> k;
    for (int i = 1; i <= 9; i++){
        dfs(1,i);
    }
    sort(ans + 1,ans + total + 1);
    cout << ans[k];
    return 0;
}