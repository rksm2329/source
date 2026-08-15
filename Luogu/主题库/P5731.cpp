#include<bits/stdc++.h>

using namespace std;

int a[20][20];

int main(){
	
	int n;
	
	cin >> n;
	
	int now = 2;
	
	int x = 1,y = 1;
	
	a[1][1] = 1;
	
	while (now <= n * n){
		
		while (y + 1 <= n && a[x][y + 1] == 0){
			
			y++;
			
			a[x][y] = now;
			
			now++;
		}
		
		while (x + 1 <= n && a[x + 1][y] == 0){
			
			x++;
			
			a[x][y] = now;
			
			now++;
		}
		
		while (y - 1 >= 1 && a[x][y - 1] == 0){
			
			y--;
			
			a[x][y] = now;
			
			now++;
		}
		
		while (x - 1 >= 1 && a[x - 1][y] == 0){
			
			x--;
			
			a[x][y] = now;
			
			now++;
		}
	}
	
	for (int i = 1; i <= n; i++){
		
		for (int j = 1; j <= n; j++){
			
			cout << setw(3) << a[i][j];
		}
		
		cout << '\n';
	}
	
	return 0;
}