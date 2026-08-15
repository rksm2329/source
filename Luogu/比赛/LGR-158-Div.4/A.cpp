#include<iostream>

using namespace std;

int a,b,c;

int main(){
    cin >> a >> b >> c;
    if (a + b == c){
        cout << "plus";
    }
    else if (a - b == c){
        cout << "minus";
    }
    else {
        cout << "illegal";
    }
    return 0;
}