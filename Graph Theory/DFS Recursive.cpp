#include<bits/stdc++.h>
using namespace std;
const int mx = 1005;
int N,E;
bool vis[mx];
vector < int > adj[mx];
void DFS(int src)
{
    vis[src] = 1;
    cout << src << endl;
    for(auto i : adj[src])
    {
        if(!vis[i])
            DFS(i);
    }
}
int main()
{
    int u,v;
    cin >> N >> E;
    for(int i=0;i<E;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
}
