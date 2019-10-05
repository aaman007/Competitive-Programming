#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 2e5+5;

ll a[MAX];
vector<ll>tree[4*MAX];

void build(int l,int r,int node)
{
    if(l == r)
    {
        tree[node].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    int left = 2*node , right = 2*node+1;
    build(l,mid,left);
    build(mid+1,r,right);

    merge(tree[left].begin(),tree[left].end(),tree[right].begin(),tree[right].end(),back_inserter(tree[node]));
}
int query(int L,int R,int l,int r,int node,ll t)
{
    if(l > R || r < L)
        return 0;
    else if(l>=L && r<=R)
        return lower_bound(tree[node].begin(),tree[node].end(),t)-tree[node].begin();
    int mid = (l+r)/2;
    return query(L,R,l,mid,2*node,t) + query(L,R,mid+1,r,2*node+1,t);
}
int main()
{

}
