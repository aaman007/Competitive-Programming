#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Info
{
    int h,a,s;
};
int m,n;
Info men[55] , women[55];
vector < int > adj[55];
int match[100];
bool vis[55];
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
    for(int i=0;i<m;i++)
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
        cin >> m >> n;
        for(int i=0;i<m;i++)
        {
            cin >> x >> y >> z;
            men[i].h = x;
            men[i].a = y;
            men[i].s = z;
        }
        for(int i=0;i<n;i++)
        {
            cin >> x >> y >> z;
            women[i].h = x;
            women[i].a = y;
            women[i].s = z;

            for(int j=0;j<m;j++)
            {
                if(abs(men[j].h-women[i].h)<=12 && abs(men[j].a-women[i].a)<=5 && !(men[j].s^women[i].s))
                    adj[j].push_back(i);
            }
        }
        cout << "Case " << cas++ << ": ";
        BPM();
        for(int i=0;i<=55;i++)
            adj[i].clear();
        memset(men,0,sizeof men);
        memset(women,0,sizeof women);
    }
}
