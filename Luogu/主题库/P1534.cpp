#include<iostream>

using namespace std;

int n,a,b,last,sum;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a >> b;
        last += a + b - 8;
        sum += last;
    }
    cout << sum;
    return 0;
}