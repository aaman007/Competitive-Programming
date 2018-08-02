#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[105],b[105];
vector < int > adj[105];
int match[105];
bool vis[105];
int dfs(int y)
{
    for(int i=0;i<adj[y].size();i++)
    {
        int z = adj[y][i];
        if(vis[z])
            continue;
        vis[z] = 1;
        if(match[z] == -1 || dfs(match[z]))
        {
            match[z] = y;
            return 1;
        }
    }
    return 0;
}
void BPM()
{
    memset(match , -1 , sizeof match);
    int total = 0;
    for(int i=0;i<n;i++)
    {
        if(adj[i].empty())
            continue;
        memset(vis,0,sizeof vis);
        if(dfs(i))
            total++;
    }
    cout << total << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,x,y,z,cas=1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> a[i];
        cin >> m;
        for(int i=0;i<m;i++)
        {
            cin >> b[i];
            for(int j=0;j<n;j++)
            {
                if(b[i]>=a[j] && (b[i]/a[j])*a[j] == b[i])
                    adj[j].push_back(i);
            }
        }
        cout << "Case " << cas++ << ": ";
        BPM();
        for(int i=0;i<=105;i++)
            adj[i].clear();
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }
}
