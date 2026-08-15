#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n,k;
	
	scanf("%d%d",&n,&k);
	
	int ret = 0;
	
	for (int i = 1; i <= n; i++)
	{
		
		int num = i;
		
		while (num > 0)
		{
			
			int s = num % 10;
			
			if (s == k)
			{
				
				ret++;
			}
			
			num /= 10;
		}
		
		num /= 10;
	}
	
	printf("%d",ret);
	
	return 0;
}