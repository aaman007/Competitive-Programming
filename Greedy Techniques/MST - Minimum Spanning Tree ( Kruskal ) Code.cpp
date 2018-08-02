#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int mx = 1005;
struct edge
{
    int u,v,w;

};
vector < edge > adj;
int N,E,par[mx];
bool cmp(edge a,edge b)
{
    return a.w < b.w;
}
int Find(int n)
{
    if(par[n]==n)
        return n;
    return par[n] = Find(par[n]);
}
int kruskal()
{
    int ans = 0 , cnt = 0 , uu , vv;
    for(int i=1;i<=N;i++)
        par[i] = i;
    for(int i=0; i<E; i++)
    {
        uu = Find(adj[i].u) , vv = Find(adj[i].v);
        if(uu!=vv)
        {
            par[uu] = vv;
            cnt++;
            ans += adj[i].w;
            if(cnt==N-1)
                break;
        }
    }
    return ans;
}
int main()
{
    int uu,vv,ww;
    edge get;
    cin >> N >> E;
    for(int i=0; i<E; i++)
    {
        cin >> uu >> vv >> ww;
        get.u = uu;
        get.v = vv;
        get.w = ww;
        adj.push_back(get);
    }
    sort(adj.begin(),adj.end(),cmp);
    cout << kruskal() << endl;
}
