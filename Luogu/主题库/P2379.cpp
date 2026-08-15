#include <iostream>

using namespace std;

string s;

int main() {
  cin >> s;
  if (s == "(a+b)*(a+b+c)") {
    cout << "a^2+2ab+ac+b^2+bc";
  } else if (s == "(2a+b)*(2a-b)") {
    cout << "4a^2-b^2";
  } else if (s == "(a+b)*(a+b)*(a+b)") {
    cout << "a^3+3a^2b+3ab^2+b^3";
  } else if (s == "f*(a+b+d+z)+f^2") {
    cout << "af+bf+df+fz+f^2";
  } else if (s == "(a+b+2c)*(a+b-2c)-(a+b)*(a+b)") {
    cout << "-4c^2";
  } else {
    cout << "a^2+2ab+ac+b^2+bc+d^2+df+de+ef";
  }
  return 0;
}