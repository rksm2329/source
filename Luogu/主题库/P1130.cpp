#include<algorithm>
#include<cstdio>

using namespace std;

const int maxn = 2005;

const int INF = 0x3f3f3f3f;

int n, m;

int a[maxn][maxn], f[maxn][maxn];

int main(){
	
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= m; ++i)
    
        for(int j = 1; j <= n; ++j)
        
            scanf("%d", &a[j][i]);
    
    for(int i = 1; i <= n; ++i)
    
        for(int j = 1; j <= m; ++j)
        
            f[i][j] = std::min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
    
    int ans = INF;
    
    for(int i = 1; i <= m; ++i)
    
        ans = std::min(ans, f[n][i]);
    
    printf("%d", ans);
    
    return 0;
}