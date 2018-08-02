#include<bits/stdc++.h>
using namespace std;
const int mx = 1005;
vector < int > adj[mx];
int main()
{
    int n,e,u,v;
    cout << "Number of nodes : ";
    cin >> n;
    cout << "Number of edges : ";
    cin >> e;
    cout << "Enter the connections\n";
    for(int i=0;i<e;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << "All connections are:\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            cout << i << " " << adj[i][j] << endl;
        }
    }
    cout << "All Nodes In degree and Out degrees are:\n";
    for(int i=1;i<=n;i++)
    {
        cout << "In Degree of node " << i << " is : " << adj[i].size() << "\t";
        cout << "Out Degree of node " << i << " is : " << adj[i].size() << endl;
    }
}
