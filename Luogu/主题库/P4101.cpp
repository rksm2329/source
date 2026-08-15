#include<iostream>

using namespace std;

int t,n,m;

int main(){
    cin >> t;
    while (t--){
        cin >> n >> m;
        if ((n - n / m + (n % m != 0)) % 2 == 0){
            cout << 1;
        }
        else {
            cout << 0;
        }
        cout << '\n';
    }
    return 0;
}