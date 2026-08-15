#include<iostream>

using namespace std;

int n,m,p;

int main(){
    cin >> n >> m >> p;
    int sum = m,ans = 0;
    for (; sum <= n; sum += p,ans++);
    cout << ans;
    return 0;
}