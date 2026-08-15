#include<iostream>
#include<iomanip>

using namespace std;

int mark[10],n,a[11];

void dfs(int dep){
	if (dep == n + 1){
		for (int i = 1; i <= n; i++){
			cout << setw(5) << a[i];
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++){	
		if (!mark[i]){
			mark[i] = 1;
			a[dep] = i;
			dfs(dep + 1);
			mark[i] = 0;
		}
	}
}

int main(){
	cin >> n;
	dfs(1);
	return 0;
}