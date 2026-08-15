#include<bits/stdc++.h>

using namespace std;

int a,b,c;

int gcd(int a,int b){
  return !b ? a : gcd(b,a % b);
}

int main(){
  cin >> a >> b >> c;
  cout << min({a,b,c}) / gcd(max({a,b,c}),min({a,b,c})) << '/' << max({a,b,c}) / gcd(max({a,b,c}),min({a,b,c}));
  return 0;
}