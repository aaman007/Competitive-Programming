#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
const int MAX = 1e5+7 , INF = 10000007;
vector < edge > adj;
long long dist[MAX];
int V,E;
void bellman_ford(int src)
{
    for(int i=1;i<=V;i++)
        dist[i] = INF;
    dist[src] = 0;
    for(int i=1;i<V;i++)
    {
        for(auto j : adj)
        {
            if(dist[j.v] > dist[j.u]+j.w)
            {
                dist[j.v] = dist[j.u]+j.w;
            }
        }
    }
}
int main()
{
    int uu,vv,ww;
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        cin >> uu >> vv >> ww;
        adj.push_back(edge(uu,vv,ww));
    }
    bellman_ford(1);
    if(dist[V]<INF)
        cout << dist[V] << endl;
    else
        cout << "No Path Found!!\n";
}
