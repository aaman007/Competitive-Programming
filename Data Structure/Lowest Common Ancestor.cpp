#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

vector<int>adj[MAX];
int dep[MAX] , T[MAX] , P[MAX][30];

void DFS(int src,int par,int lev)
{
    dep[src] = lev;
    T[src] = par;

    for(int i=0;i<adj[src].size();i++)
    {
        int x = adj[src][i];

        if(x == par)
            continue;
        DFS(x,src,lev+1);
    }
}
void initLCA(int n)
{
    memset(P,-1,sizeof P);

    for(int i=1;i<=n;i++)
        P[i][0] = T[i];

    for(int j=1; 1<<j <n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int query(int n,int u,int v)
{
    if(dep[u] < dep[v])
        swap(u,v);

    int log = 1;

    while(1)
    {
        int next = log+1;
        if((1<<next) > dep[u])
            break;
        log++;
    }

    for(int i=log;i>=0;i--)
    {
        if(dep[u]-(1<<i) >= dep[v])
            u = P[u][i];
    }

    if(u == v)
        return u;

    for(int i=log;i>=0;i--)
    {
        if(P[u][i] != -1 && P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}
int main()
{
    int n,m,u,v;

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    DFS(1,1,0);

    initLCA(n);

    int q;

    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        cout << query(n,u,v) << endl;
    }
}
