#include<iostream>

using namespace std;

int n,arr[1 << 10 + 1][1 << 10 + 1];

int main(){
    cin >> n;
    n = 1 << n;
    arr[0][n + 1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            arr[i][j] = (arr[i - 1][j] + arr[i - 1][j + 1]) % 2;
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}