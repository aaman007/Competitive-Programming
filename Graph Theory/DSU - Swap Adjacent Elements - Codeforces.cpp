
#include<bits/stdc++.h>
#define pii pair<int,int>
#define sf(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) (x.begin(),x.end())
#define rall(x) (x.rbegin(),x.rend())
#define pb push_back
#define F first
#define S second
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
const int MX = 2e5+5;
int par[MX];
int Find(int u)
{
    if(par[u] == u)
        return u;
    else
        return par[u] = Find(par[u]);
}
void Union(int u,int v)
{
    u = Find(u);
    v = Find(v);
    par[u] = v;
}
int main()
{
    int n;
    sf(n);
    int a[n+2];
    string s;
    for(int i=0;i<n;i++)
        sf(a[i]);
    cin >> s;

    for(int i=1;i<=n;i++)
        par[i] = i;

    for(int i=0;i<n-1;i++)
    {
        if(s[i] == '1')
            Union(i+1,i+2);
    }
    for(int i=1;i<=n;i++)
    {
        if(Find(i) != Find(a[i-1]))
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
