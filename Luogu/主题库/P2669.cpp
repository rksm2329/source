#include<iostream>

using namespace std;

int k;

int main(){
    cin >> k;
    int day = 0;
    long long ans = 0;
    for (int i = 1; ; i++){
        for (int j = 1; j <= i; j++){
            day++;
            ans += i;
            if (day == k){
                cout << ans;
                return 0;
            }
        }
    }
    return 0;
}