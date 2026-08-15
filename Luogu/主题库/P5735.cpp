#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double dis(double x1,double y1,double x2,double y2){
    return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}

int main(){
    double x1,y1,x2,y2,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << fixed << setprecision(2) << dis(x1,y1,x2,y2) + dis(x2,y2,x3,y3) + dis(x3,y3,x1,y1);
    return 0;
}