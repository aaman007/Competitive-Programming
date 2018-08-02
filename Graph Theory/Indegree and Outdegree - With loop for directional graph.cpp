#include<bits/stdc++.h>
using namespace std;
const int mx = 1005;
vector < int > adj[mx];
int main()
{
    int n,e,u,v,cnt;
    cout << "Number of nodes : ";
    cin >> n;
    cout << "Number of edges : ";
    cin >> e;
    cout << "Enter the connections\n";
    for(int i=0;i<e;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    cout << "All Node's Indegree and Outdegrees are:\n";
    for(int i=1;i<=n;i++)
    {
        cnt = 0;
        cout << "Outegree of " << i << " is : ";
        cout << adj[i].size() << "\t";
        cout << "Indegree of " << i << " is : ";
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<adj[j].size();k++)
            {
                if(adj[j][k]==i)
                {
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}
