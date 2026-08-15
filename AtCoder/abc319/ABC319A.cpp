#include<iostream>
#include<map>

using namespace std;

string s;
map<string,int> p;

int main(){
    p["tourist"] = 3858,p["ksun48"] = 3679,p["Benq"] = 3658,p["Um_nik"] = 3648,p["apiad"] = 3638,p["Stonefeang"] = 3630,p["ecnerwala"] = 3613,p["mnbvmar"] = 3555,p["newbiedmy"] = 3516,p["semiexp"] = 3481;
    cin >> s;
    cout << p[s];
    return 0;
}