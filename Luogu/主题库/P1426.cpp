#include<iostream>

using namespace std;

double v = 7,s,x,sum;

int main(){
    cin >> s >> x;
    for (; sum < s - x; ){
        sum += v;
        v *= 0.98;
    }
    cout << (v * 0.98 <= s + x - sum ? "y" : "n");
    return 0;
}