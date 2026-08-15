#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    double a = (pow((1 + sqrt(5)) * 1.0 / 2,n) - pow((1 - sqrt(5)) * 1.0 / 2,n)) * 1.0 / (sqrt(5));

    printf("%.2f",a);

    return 0;
}