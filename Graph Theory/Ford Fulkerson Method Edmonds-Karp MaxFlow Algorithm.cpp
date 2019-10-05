#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 105;

int residualCapacity[MAX][MAX] , capacity[MAX][MAX];
int par[MAX];
bool vis[MAX];

bool BFS(int s,int t)
{
    for(int i=1;i<MAX;i++)
        par[i] = i;

    queue<int>q;
    memset(vis,0,sizeof vis);
    q.push(s);
    vis[s] = 1;

    while(q.size())
    {
        int u = q.front();
        q.pop();

        for(int v=1;v<MAX;v++)
        {
            if(!vis[v] && residualCapacity[u][v])
            {
                par[v] = u;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    return vis[t];
}
int fordFulkerson(int s,int e)
{
    for(int i=1;i<MAX;i++)
        for(int j=1;j<MAX;j++)
            residualCapacity[i][j] = capacity[i][j];

    int maxFlow = 0;
    while(BFS(s,e))
    {
        int flow = INT_MAX , cur = e;

        while(cur != s)
        {
            flow = min(flow,residualCapacity[par[cur]][cur]);
            cur = par[cur];
        }

        maxFlow += flow;

        cur = e;
        while(cur != s)
        {
            residualCapacity[par[cur]][cur] -= flow;
            residualCapacity[cur][par[cur]] += flow;
            cur = par[cur];
        }
    }

    return maxFlow;
}

int main()
{
    FastRead

    int t,cas=1;

    cin >> t;

    while(t--)
    {
        int n,m,u,v,c,s,e;

        cin >> n >> s >> e >> m;

        memset(capacity,0,sizeof capacity);

        while(m--)
        {
            cin >> u >> v >> c;

            capacity[u][v] += c;
            capacity[v][u] += c;
        }

        cout << "Case " << cas++ << ": " << fordFulkerson(s,e) << endl;
    }
}
