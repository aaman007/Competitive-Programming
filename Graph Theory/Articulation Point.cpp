#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

vector<int>adj[MAX];
set<int>articulationPoints;
bool vis[MAX];
int dist[MAX] , lowTime[MAX] , timo;

void init()
{
    timo = 0;
    memset(dist,0,sizeof dist);
    memset(lowTime,0,sizeof lowTime);
    memset(vis,0,sizeof vis);
    articulationPoints.clear();
    for(int i=0;i<MAX;i++)
        adj[i].clear();
}
void DFS(int src,int par)
{
    vis[src] = 1;
    dist[src] = timo++;
    lowTime[src] = dist[src];

    int child = 0;

    for(auto i : adj[src])
    {
        if(i == par)
            continue;
        if(!vis[i])
        {
            DFS(i,src);
            lowTime[src] = min(lowTime[src],lowTime[i]);

            if(dist[src] <= lowTime[i] && par != -1)
                articulationPoints.insert(src);
            child++;
        }
        else
            lowTime[src] = min(lowTime[src],dist[i]);
    }
    if(child > 1 && par == -1)
        articulationPoints.insert(src);
}
void findArticulationPoints()
{
    DFS(1,-1);

    cout << "Articulation Points are : ";
    for(auto i : articulationPoints)
        cout << i << " -> ";
    cout << endl;
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

    findArticulationPoints();
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
A.P : 3,4,5,6
**/
