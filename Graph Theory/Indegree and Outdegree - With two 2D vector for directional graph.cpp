
#include<bits/stdc++.h>
using namespace std;
const int mx = 1005;
vector < int > adj[mx];
int in[mx] , out[mx];
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
        in[v]++;
        out[u]++;

    }
    cout << "All Nodes In degree and Out degrees are:\n";
    for(int i=1;i<=n;i++)
    {
        cout << "In and out degree of " << i << " is : ";
        cout << in[i] << " " << out[i] << endl;
    }
}
