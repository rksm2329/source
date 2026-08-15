#include<iostream>

using namespace std;

string s;

int main(){
  getline(cin,s);
  int ans1 = 0,ans2 = 0;
  for (int pos = 0; s.find("\\r",pos) != string::npos; pos = s.find("\\r",pos) + 1,ans1++){
  }
  for (int pos = 0; s.find("\\n",pos) != string::npos; pos = s.find("\\n",pos) + 1,ans2++){
  }
  if (ans1 == ans2){
    cout << "windows";
  }
  else if (ans1 < ans2){
    cout << "linux";
  }
  else {
    cout << "mac";
  }
  return 0;
}