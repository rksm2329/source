#include<iostream>

using namespace std;

int t,n;

int main(){
    for (cin >> t; t; t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cout << i + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}