#include<iostream>

using namespace std;

const int MAXN = 1e6 + 10;

int t;
long long arr[MAXN];
long long x,a;

int main(){
    cin >> t;
    while (t--){
        cin >> x >> a;
        arr[0] = x;
        cout << x << ' ';
        for (int i = 1; ; i++){
            arr[i] = (arr[i - 1] + a) / a;
            if (arr[i] == arr[i - 1]){
                cout << '\n';
                break;
            }
            cout << arr[i] << ' ';
        }
    }
    return 0;
}