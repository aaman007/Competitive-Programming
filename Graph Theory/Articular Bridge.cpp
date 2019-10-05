#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

vector<int>adj[MAX];
set<pii>bridges;
bool vis[MAX];
int dist[MAX] , lowTime[MAX] , timo;

void init()
{
    timo = 0;
    memset(vis,0,sizeof vis);
    memset(dist,0,sizeof dist);
    memset(lowTime,0,sizeof lowTime);

    for(int i=0;i<MAX;i++)
        adj[i].clear();
}
void addBridge(int u,int v)
{
    if(u > v)
        swap(u,v);
    bridges.insert({u,v});
}
void DFS(int src,int par)
{
    vis[src] = 1;
    dist[src] = lowTime[src] = timo++;

    for(auto i : adj[src])
    {
        if(i == par)
            continue;
        if(!vis[i])
        {
            DFS(i,src);
            lowTime[src] = min(lowTime[src],lowTime[i]);

            if(dist[src] < lowTime[i])
                addBridge(i,src);
        }
        else
            lowTime[src] = min(lowTime[src],dist[i]);
    }
}
void findBridges()
{
    DFS(1,-1);

    cout << "Articular Bridges are :\n";
    for(auto i : bridges)
        cout << i.first << "->" << i.second << endl;
}
int main()
{
    FastRead

    int n,m,u,v;

    init();

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findBridges();
}
/**
8 9
1 2
1 3
2 3
3 4
4 5
5 6
5 7
7 6
6 8
Articular Bridges are :
3->4
4->5
6->8
**/
