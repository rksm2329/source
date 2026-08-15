#include <iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int a[1000010],n;

long long ans;

int main(){
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		
		cin >> a[i];
		
		pq.push(a[i]);
	}
	
	for(int i = 1; i <= n - 1; i++){
		
		int a = pq.top();
		
		pq.pop();
		
		int b = pq.top();
		
		pq.pop();
		
		ans += a + b;
		
		pq.push(a + b);
	}
	
	cout << ans << endl;
	
	return 0;
}
