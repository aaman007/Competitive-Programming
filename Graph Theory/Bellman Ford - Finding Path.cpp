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
const int MAX = 1e5+7 , INF = 1e7+7;
vector < edge > adj;
long long dist[MAX];
int par[MAX];
int V,E;
void bellman_ford(int src)
{
    for(int i=1;i<=V;i++)
        dist[i] = INF;
    dist[src] = 0;
    par[src] = -1;
    for(int i=1;i<V;i++)
    {
        int flag = 0;
        for(auto j : adj)
        {
            if(dist[j.v] > dist[j.u]+j.w)
            {
                dist[j.v] = dist[j.u]+j.w;
                par[j.v] = j.u;
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
}
void print_path(int src,int node)
{
    vector < int > path;
    int i = node;
    while(i!=-1)
    {
        path.push_back(i);
        i = par[i];
    }
    for(i=path.size()-1;i>=0;i--)
        cout << path[i] << " ";
    cout << endl;
}
bool negetive_cycle(int src)
{
    bellman_ford(src);
    for(auto i : adj)
    {
        if(dist[i.v] > dist[i.u]+i.w)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int uu,vv,ww;
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        cin >> uu >> vv >> ww;
        adj.push_back(edge(uu,vv,ww));
    }
    if(negetive_cycle(1))
        cout << "Negetive Cycle is found!!\n";
    else if(dist[V]<INF)
        print_path(1,V);
    else
        cout << -1 << endl;
}
