#include<iostream>

using namespace std;

long long n;

long long mul(int a,int b){
    long long ans = 1;
    for (int i = 1; i <= b; i++){
        ans *= a;
    }
    return ans;
}

int main(){
    cin >> n;
    int mx = 0;
    for (int i = 0; ; i++){
        if (mul(2,i) < n){
            if (i % 2 == 0){
                mx = i;
            }
        }
        else {
            break;
        }
    }
    cout << mx;
    return 0;
}