#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

vector<int>adj[MAX];
int root , mx;

void DFS(int src,int par,int lev)
{
    if(lev > mx)
    {
        mx = lev;
        root = src;
    }
    for(auto i : adj[src])
    {
        if(i != par)
            DFS(i,src,lev+1);
    }
}

int main()
{
    int n,u,v;

    cin >> n;

    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root = 1;
    DFS(root,-1,0);

    int root1 = root;
    DFS(root,-1,0);

    cout << root1 << " -> " << root << " : " << mx << endl;
}
