#include<iostream>

using namespace std;

const int MAXN = 1e6 + 10;

int n,a[MAXN];

int main(){

    cin >> n;

    for (int i = 1; i <= n; i++){

        cin >> a[i];
    }

    int cnt = 0,mx = 0;

    for (int i = 1; i <= n; i++){

        if (a[i] >= a[i - 1]){

            cnt++;
        }
        else {

            // cout << "i=" << i << ' ' << "cnt=" << cnt << '\n';

            mx = max(mx,cnt);

            cnt = 1;
        }
    }

    mx = max(mx,cnt);

    cout << mx;

    return 0;
}