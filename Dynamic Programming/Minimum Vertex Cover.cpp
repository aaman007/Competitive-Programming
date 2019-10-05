#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

int dp[MAX][2];

vector<int>adj[MAX];

int DP(int src,int isGuard,int par)
{
    if(~dp[src][isGuard])
        return dp[src][isGuard];

    int sum = 0;
    for(auto i : adj[src])
    {
        if(i == par)
            continue;

        if(isGuard)
            sum += min(DP(i,1,src),DP(i,0,src));
        else
            sum += DP(i,1,src);
    }

    return dp[src][isGuard] = sum + isGuard;
}

int main()
{
    FastRead

    int n,u,v;

    cin >> n;

    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp,-1,sizeof dp);

    if(n == 1)
        cout << 0 << endl;
    else
        cout << min(DP(1,1,-1),DP(1,0,-1)) << endl;
}
