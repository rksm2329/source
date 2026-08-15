#include<iostream>

using namespace std;

int x[5],y[5],cnt[210];

int main(){
	for (int i = 1; i <= 3; i++){
		cin >> x[i] >> y[i];
	}
	int xans = 0,yans = 0;
	if (x[1] == x[2]){
		xans = x[3];
	}
	if (x[2] == x[3]){
		xans = x[1];
	}
	if (x[1] == x[3]){	
		xans = x[2];
	}
	if (y[1] == y[2]){
		yans = y[3];
	}
	if (y[2] == y[3]){
		yans = y[1];
	}
	if (y[1] == y[3]){		
		yans = y[2];
	}
	cout << xans << ' ' << yans;
	return 0;
}