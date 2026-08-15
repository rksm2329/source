#include<iostream>

using namespace std;

int n;

long long fact(int n){
    if (n == 1){
        return 1;
    }
    return 1ll * n * fact(n - 1);
}

int main(){
    cin >> n;
    cout << fact(n);
    return 0;
}