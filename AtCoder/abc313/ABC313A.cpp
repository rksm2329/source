#include<iostream>

using namespace std;

int n,a[110],cnt[110];

int main(){

    cin >> n;

    int mx = 0;

    for (int i = 1; i <= n; i++){

        cin >> a[i];

        mx = max(mx,a[i]);

        cnt[a[i]]++;
    }

    cout << (a[1] == mx && cnt[mx] == 1 ? 0 : mx - a[1] + 1);

    return 0;
}