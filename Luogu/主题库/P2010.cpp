#include<iostream>

using namespace std;

const int month[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int n,m,ans;

int main(){
	cin >> n >> m;
	for (int i = 1; i <= 12; i++){
		for (int j = 1; j <= month[i - 1]; j++){
			int tmp = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
			if (tmp * 10000 + i * 100 + j < n || tmp * 10000 + i * 100 + j > m){
				continue;
			}
			ans++;
		}
	}
	cout << ans;
	return 0;
}