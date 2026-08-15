#include<bits/stdc++.h>

using namespace std;

int a[500010];

int main(){
	
    int n;
	
    cin >> n;
	
    for (int i = 1; i <= n; i++){
		
        cin >> a[i];
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++){
    	
    	for (int j = i + 1; j <= n; j++){
    		
    		if (j = i + 1){
    			
    			cnt++;
    		}
    		
    		int flag = 0;
    		
    		for (int k = i; k <= j; k++){
    			
    			if (a[k] > a[i] || a[k] > a[j]){
    				
    				flag = 1;
    				
    				break;
    			}
    		}
    		
    		if (flag == 0) cnt++;
    	}
    }
    
    cout << cnt;
	
    return 0;
}