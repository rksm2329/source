#include<iostream>

using namespace std;

string s;

int main(){
    cin >> s;
    if (s.size() == 8 && s[0] >= 'A' && s[0] <= 'Z' && s[s.size() - 1] >= 'A' && s[s.size() - 1] <= 'Z'){
        bool f = 0;
        for (int i = 1; i < 7; i++){
            if (!((i == 1 && s[i] >= '1' && s[i] <= '9') || (i != 1 && s[i] >= '0' && s[i] <= '9'))){
                f = 1;
            }
        }
        !f ? cout << "Yes" : cout << "No";
    }
    else {
        cout << "No";
    }
    return 0;
}