
#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define sf(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)
#define mem(a,b) memset(a,b,sizeof(a))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define F first
#define S second
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int par[130];
int Find(int u)
{
    if(par[u] == u)
        return u;
    else return par[u] = Find(par[u]);
}
void Union(int u,int v)
{
    u = Find(u) , v = Find(v);
    par[u] = v;
}
int main()
{
    for(int i=1;i<=28;i++)
        par[i] = i;
    int n;
    cin >> n;
    vector < string > ans;
    string s,s1,temp;
    cin >> s >> s1;
    for(int i=0;i<n;i++)
    {
        if(Find(s[i]-'a') != Find(s1[i]-'a'))
        {
            Union(s[i]-'a',s1[i]-'a');
            temp = s[i] , temp += " " , temp += s1[i];
            ans.push_back(temp);
        }
    }
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << endl;
}
