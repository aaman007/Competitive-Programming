#include<bits/stdc++.h>
using namespace std;
const int mx = 1005 , inf = INFINITY;
int N,E;
int adj[mx][mx],path[mx][mx];
void floydWarsh()
{
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j] && adj[i][k]!=inf && adj[k][j]!=inf)
                {
                    adj[i][j] = adj[i][k]+adj[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}
void findPath(int i,int j)
{
    vector < int > vec;
    while(i!=j)
    {
        if(i==-1)
        {
            cout << "No Path Found!!\n";
            return;
        }
        vec.push_back(i);
        i = path[i][j];
    }
    vec.push_back(i);
    cout << "Path : ";
    for(auto i:vec)
    {
        cout << i << "->";
    }
    cout << endl;
}
int main()
{
    int u,v,w;
    cin >> N >> E;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            path[i][j] = -1;
            adj[i][j] = inf;
        }
    }
    for(int i=1; i<=N; i++)
        adj[i][i] = 0, path[i][i] = i;

    for(int i=0; i<E; i++)
    {
        cin >> u >> v >> w;
        adj[u][v] = w;
        path[u][v] = v;
    }
    floydWarsh();
    while(1)
    {
        int a,b;
        cin >> a >> b;
        findPath(a,b);
        cout << "Distance : " << adj[a][b] << endl;
    }
}
