#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e4 + 10;

int n,b,a[MAXN];

bool cmp(const int &i,const int &j){
	return i > j;
}

int main(){
	cin >> n >> b;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	stable_sort(a + 1,a + n + 1,cmp);
	int sum = 0,cnt = 0;
	for (int i = 1; i <= n; i++){
		sum += a[i],cnt++;
		if (sum >= b){
			break;
		}
	}
	cout << cnt;
	return 0;
}