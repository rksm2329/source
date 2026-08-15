#include<iostream>

using namespace std;

const int MAXN = 100;

int n,fact[MAXN],cnt;

int main(){
    cin >> n;
    for (int i = 1; i <= 9; i++){
        if (n % i == 0){
            fact[++cnt] = i;
        }
    }
    for (int i = 0; i < n + 1; i++){
        bool haveAns = 0;
        for (int j = 1; j <= cnt; j++){
            if (i % (n / fact[j]) == 0){
                cout << fact[j];
                haveAns = 1;
                break;
            }
        }
        if (!haveAns){
            cout << '-';
        }
    }
    return 0;
}