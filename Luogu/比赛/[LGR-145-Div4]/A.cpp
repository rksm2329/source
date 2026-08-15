#include<iostream>

using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	if (a + b + c <= 100 && b % 5 == 0 && c % 7 == 0 && a - b > b - c){
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}