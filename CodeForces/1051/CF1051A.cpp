#include<iostream>

using namespace std;

int t,cnt_sl,cnt_bl,cnt_num;
int index_sl,index_bl,index_num;
string s;

void count_sign() {
    cnt_sl = 0,cnt_bl = 0,cnt_num = 0;
    index_sl = -1,index_bl = -1,index_num = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cnt_sl++;
            index_sl = i;
        }
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cnt_bl++;
            index_bl = i;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            cnt_num++;
            index_num = i;
        }
    }
}

void replace(int x){
    char c;
    if (x == 1){
        c = 'a';
    }
    if (x == 2){
        c = 'A';
    }
    if (x == 3){
        c = '0';
    }
    count_sign();
    if (cnt_sl >= 2){
        s[index_sl] = c;
    }
    else if (cnt_bl >= 2){
        s[index_bl] = c;
    }
    else if (cnt_num >= 2){
        s[index_num] = c;
    }
}

int main(){
    cin >> t;
    while (t--){
        cin >> s;
        count_sign();
        if (cnt_sl == 0){
            replace(1);
        }
        if (cnt_bl == 0){
            replace(2);
        }
        if (cnt_num == 0){
            replace(3);
        }
        cout << s << '\n';
    }
    return 0;
}