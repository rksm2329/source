#include<bits/stdc++.h>

using namespace std;

int n,a[1024] = {1};

int main(){
  cin >> n;
  n = 1 << n;
  for (int i = 0; i < n; i++,cout << '\n'){
    for (int j = 1; j < n - i; j++){
      cout << ' ';
    }
    for (int j = i; j >= 0; j--){
      a[j] ^= a[j - 1];
    }
    if (i % 2 == 0){
      for (int j = 0; j <= i; j++){
        cout << (a[j] ? "/\\" : "  ");
      }
    }
    else {
      for (int j = 0; j <= i; j += 2){
        cout << (a[j] ? "/__\\" : "    ");
      }
    }
  }
  return 0;
}