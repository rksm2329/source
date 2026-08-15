#include<iostream>

using namespace std;

int x1,x2,y1,y2;
char c;

int gcd(int x,int y){
    return !y ? x : gcd(y,x % y);
}

int main(){
    cin >> x1 >> c >> y1 >> x2 >> c >> y2;
    int t1 = x1 * x2,t2 = y1 * y2;
    cout << t2 / gcd(t1,t2) << ' ' << t1 / gcd(t1,t2);
    return 0;
}