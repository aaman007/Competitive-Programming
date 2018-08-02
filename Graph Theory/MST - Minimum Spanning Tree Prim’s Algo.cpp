#include
#define pii pair
using namespace std;
const int MAX = 100005;
struct node
{
    int u,w;
    node(){}
    node(int _u,int _w)
    {
        u = _u;
        w = _w;
    }
};
bool operator b.w;
}
int cost[MAX],vis[MAX],n,e;
priority_queue pq;
vector  adj[MAX];
int prim(int src)
{
    for(int i=1;i<=n;i++)
        cost[i] = INFINITY;
    int ans = 0;
    cost[src] = 0;
    pq.push(node(src,cost[src]));
    while(!pq.empty())
    {
        node temp = pq.top();
        pq.pop();
        if(vis[temp.u])
            continue;
        vis[temp.u] = 1;
        ans += temp.w;
        for(auto v : adj[temp.u])
        {
            if(vis[v.first])
                continue;
            else if(v.second > n >> e;
    int u,v,w;
    for(int i=0;i> u >> v >> w;
        adj[u].push_back(pii(v,w));
        adj[v].push_back(pii(u,w));
    }
    cout << "Minimum Cost : " << prim(1) << endl;
}
