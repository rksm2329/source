#include<iostream>

using namespace std;

long long n,m,p,q;

int main(){
    cin >> n >> m >> p >> q;
    if (p * m + q + 1 <= n * m){
        cout << "Program ends with return value 0.";
    }
    else {
        cout << "Segmentation fault.";
    }
    return 0;
}