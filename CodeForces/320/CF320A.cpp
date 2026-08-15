#include<iostream>

using namespace std;

int n;

int main(){
    cin >> n;
    while (1){
        if (n % 10 == 1){
            n /= 10;
            continue;
        }
        if (n % 100 == 14){
            n /= 100;
            continue;
        }
        if (n % 1000 == 144){
            n /= 1000;
            continue;
        }
        if (!n){
            cout << "YES";
            return 0;
        }
        cout << "NO\n";
        return 0;
    }
    return 0;
}