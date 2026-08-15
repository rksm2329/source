#include <iostream>

using namespace std;

int s, t, w;
string num;

int main(){
  cin >> s >> t >> w >> num;
  for (int i = 1; i <= 5; i++){
    for (int j = w - 1; j >= 0; j--){
      if (num[j] - 96 <= j - w + t){
        num[j]++;
        for (int k = j + 1; k < w; k++){
          num[k] = num[k - 1] + 1;
        }
        cout << num << '\n';
        break;
      }
    }
  }
  return 0;
}