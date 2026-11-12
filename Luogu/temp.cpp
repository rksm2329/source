#include<bits/stdc++.h>
#include<bits/extc++.h>
#define double long double
#define unsigned unsigned int
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int n,m,a[100005];long ans,tre[100005];
vector<int>fa[500005],vec[500005];
inline int read()
{
    int x=0,op=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9')
    {
        if(c=='-')op=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar_unlocked();
    }
    return x*op;
}
inline void write(long x)
{
    if(x<0)
    {
        x*=-1;
        putchar_unlocked('-');
    }
    if(x>=10)write(x/10);
    putchar_unlocked(x%10+'0');
    return;
}
inline int getfa(int x,int i)
{
    if(i==fa[x][i])return i;
    if(i==fa[x].size())return i;
    fa[x][i]=getfa(x,fa[x][i]);
    return fa[x][i];
}
inline int lowbit(int x)
{
    int i=x&(-x);
    return i;
}
inline void update(int x,int k)
{
    while(x<=n)
    {
        tre[x]+=k;
        x+=lowbit(x);
    }
    return;
}
inline long getsum(int x)
{
    long res=0;
    while(x!=0)
    {
        res+=tre[x];
        x-=lowbit(x);
    }
    return res;
}
signed main()
{
    n=read(),m=read();
    for(register int i=1;i<=n;i++)
    {
        a[i]=read();
        update(i,a[i]);
        for(register int j=1;j*j<=a[i];j++)
            if(a[i]%j==0)
            {
                vec[j].push_back(i);
                fa[j].push_back(fa[j].size());
                if(j*j==a[i])continue;
                vec[a[i]/j].push_back(i);
                fa[a[i]/j].push_back(fa[a[i]/j].size());
            }
    }
    while(m--)
    {
        int l,r,op=read();
        l=read(),r=read();
        l^=ans,r^=ans;
        if(op==1)
        {
            int x=ans^read();
            if(x==1||vec[x].empty())
                continue;
            int u=lower_bound(vec[x].begin(),vec[x].end(),l)-vec[x].begin();
            for(register int i=getfa(x,u);i<vec[x].size()&&vec[x][i]<=r;i=getfa(x,i+1))
            {
                int it=vec[x][i];
                if(a[it]%x==0)
                {
                    int num=-a[it]+a[it]/x;
                    update(it,num);
                    a[vec[x][i]]/=x;
                }
                if(a[it]%x)fa[x][i]=i+1;
            }
        }
        else
        {
            ans=getsum(r)-getsum(l-1);
            write(ans);putchar('\n');
        }
    }
    return 0;
}
