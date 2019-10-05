#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3+10;

vector < int > graph[MAX] , reverseGraph[MAX] , components[MAX];
bool vis[MAX];
int compCount;
stack<int>nodes;

void DFS(int src)
{
    vis[src] = 1;
    for(auto i : graph[src])
    {
        if(!vis[i])
            DFS(i);
    }
    nodes.push(src);
}
void DFS2(int src)
{
    vis[src] = 1;
    for(auto i : reverseGraph[src])
    {
        if(!vis[i])
            DFS2(i);
    }
    components[compCount].push_back(src);
}
void init()
{
    compCount = 1;
    for(int i=1;i<MAX;i++)
        graph[i].clear() , reverseGraph[i].clear() , components[i].clear();
}
void addEdge(int u,int v)
{
    graph[u].push_back(v);
    reverseGraph[v].push_back(u);
}
void kosaraju_SCC(int n)
{
    memset(vis,0,sizeof vis);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            DFS(i);
    }

    memset(vis,0,sizeof vis);

    while(nodes.size())
    {
        int top = nodes.top();
        nodes.pop();

        if(!vis[top])
        {
            DFS2(top);
            compCount++;
        }
    }
}
void print_SCCs()
{
    for(int i=1;i<compCount;i++)
    {
        cout << "Component " << i << ":\n";
        for(auto j : components[i])
            cout << j << " -> ";
        cout << endl;
    }
}
int main()
{
    int n,m,u,v;

    init();

    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        addEdge(u,v);
    }

    kosaraju_SCC(n);

    print_SCCs();
}
