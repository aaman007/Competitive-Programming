/// Topological Sort Code with Adjacency Matrix :
#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
bool adj[MAX][MAX] , vis[MAX];
int  node , edge , indegree[MAX];
int main()
{
    int u,v;
    cout << "Enter the number of nodes and edges : ";
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        indegree[v]++;
    }
    for(int i=1;i<=node;i++)
        cout << "Indegree of " << i << " is : " << indegree[i] << endl;
    cout << "Topological Sort : ";
    for(int i=0;i<edge;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(!indegree[j] && !vis[j])
            {
                cout << j << "->";
                vis[j] = 1;
                for(int k=1;k<=node;k++)
                {
                    if(adj[j][k])
                        indegree[k]--;
                }
            }
        }
    }
    cout << endl;
}

///Topological Sort code with Adjacency List :
#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;
vector < int > adj[MAX];
int indegree[MAX];
bool vis[MAX];
int node , edge;
int main()
{
    int u,v;
    cout << "Enter the number of nodes and edges : ";
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    for(int i=1;i<=node;i++)
        cout << "Indegree of " << i << " is : " << indegree[i] << endl;

    cout << "\nTopSort of given nodes/edges are :\n";
    int temp;
    for(int i=0;i<edge;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(!indegree[j] && !vis[j])
            {
                cout << j << endl;
                vis[j] = 1;
                for(int k=0;k<adj[j].size();k++)
                {
                    temp = adj[j][k];
                    indegree[temp]--;
                }
            }
        }
    }
}

/// We can also use edge– in both code in the Topological loop section so that the outer loop doesn’t run unnecessarily :
for(int i=0;i<edge;i++)
   {
       for(int j=1;j<=node;j++)
       {
           if(!indegree[j] && !vis[j])
           {
               cout << j << endl;
               vis[j] = 1;
               for(int k=0;k<adj[j].size();k++)
               {
                   temp = adj[j][k];
                   indegree[temp]--;
               }
               edge--;
           }
       }
   }

/// Topological Sort with BFS :
#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector < int > adj[MAX];
int in[MAX];
int node,edge;
queue < int > q;
void topSort_BFS()
{
    while(!q.empty())
    {
        int v,u = q.front();
        q.pop();
        cout << u << endl;
        for(int i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            in[v]--;
            if(in[v]==0)
            {
                q.push(v);
            }
        }
    }
}
int main()
{
    int u,v;
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
       cin >> u >> v;
       adj[u].push_back(v);
       in[v]++;
    }
    for(int i=1;i<=node;i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    topSort_BFS();
}

/// Topological Sort with BFS – 2 :
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int MAX = 105;
struct Node
{
    int first,second;
    Node(){}   /// Default Constructor
    Node(int _f,int _s)
    {
        first = _f;
        second = _s;
    }
};
bool operator<(Node A,Node B)
{
    return A.second > B.second;
}
vector < int > adj[MAX];
int in[MAX];
int node,edge;
bool vis[MAX];
priority_queue < Node> q;
void topSort_BFS()
{
    while(!q.empty())
    {
        int v,u = q.top().second , w = q.top().first;
        q.pop();
        cout << u << endl;
        for(int i=0;i<adj[u].size();i++)
        {
            v = adj[u][i];
            in[v]--;
            if(!vis[v] && in[v]==0)
            {
                vis[v] = 1;
                q.push(Node(in[v],v));
            }
        }
    }
}
int main()
{
    int u,v;
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
       cin >> u >> v;
       adj[u].push_back(v);
       in[v]++;
    }
    int mn_node , mn = INT_MAX;
    for(int i=1;i<=node;i++)
    {
        if(in[i]==0)
            q.push(Node(in[i],i));
    }
    topSort_BFS();
}

/// Topological Sort with DFS :
#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
vector < int > adj[MAX];
int node,edge,flag=0;
int visited[MAX];
vector < int > ans;
void topSort_DFS(int src)
{
    if(visited[src]==1)
    {
        cout << "There is cycle in this graph.TopSort can't be performed\n";
        ans.clear();
        flag = 1;
        return;
    }
    visited[src] = 1;
    for(int i=0;i<adj[src].size();i++)
    {
        if(visited[adj[src][i]]!=2)
            topSort_DFS(adj[src][i]);
    }
    if(!flag)
        ans.push_back(src);
    visited[src] = 2;
}
int main()
{
    int u,v;
    cout << "Enter the number of nodes & edges : ";
    cin >> node >> edge;
    for(int i=0;i<edge;i++)
    {
       cin >> u >> v;
       adj[u].push_back(v);
    }
    for(int i=1;i<=node;i++)
    {
        if(!visited[i])
            topSort_DFS(i);
    }
    if(!ans.empty())
    {
        reverse(ans.begin(),ans.end());
        cout << "Topological Sort is :\n";
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << "->";
        cout << endl;
    }
}
