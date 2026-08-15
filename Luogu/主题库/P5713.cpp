#include<iostream>

using namespace std;

int n;

int main(){
  cin >> n;
  cout << (n * 5 < 11 + n * 3 ? "Local" : "Luogu");
  return 0; 
}