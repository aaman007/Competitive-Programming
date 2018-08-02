#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
bool Check(ll n,ll pos) { return (n>>pos)&1; }
const int MAX = 1e5+5;
ll a[MAX];
struct TREE
{
    int bit[65]={0};
}tree[MAX*4];
void build(int l,int r,int pos)
{
    if(l == r)
    {
        for(int i=0;i<=60;i++)
        {
            if(Check(a[l],i))
                tree[pos].bit[i] = 1;
        }
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,pos*2);
    build(mid+1,r,pos*2+1);
    for(int i=0;i<=60;i++)
        tree[pos].bit[i] = tree[2*pos].bit[i]+tree[2*pos+1].bit[i];
    return;
}
void update(int l,int r,int pos,int idx,int x)
{
    if(idx < l || idx > r)
        return;
    if(l == r)
    {
        a[idx] = x;
        for(int i=0;i<61;i++)
        {
            if(Check(a[l],i))
                tree[pos].bit[i] = 1;
            else
                tree[pos].bit[i] = 0;
        }
        return;

    }
    int mid = (l+r)/2;
    update(l,mid,2*pos,idx,x);
    update(mid+1,r,2*pos+1,idx,x);
    for(int i=0;i<=60;i++)
        tree[pos].bit[i] = tree[2*pos].bit[i]+tree[2*pos+1].bit[i];
    return;
}
ll query(int L,int R,int l,int r,int pos,int k)
{
    if(l>=L && r<=R)
        return tree[pos].bit[k];
    else if(l>R || r<L)
        return 0;
    int mid = (l+r)/2;
    int q1 = query(L,R,l,mid,pos*2,k);
    int q2 = query(L,R,mid+1,r,pos*2+1,k);
    return q1+q2;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    build(1,n,1);
    int q,type,i,x,l,r,k;
    cin >> q;
    while(q--)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> i >> x;
            update(1,n,1,i,x);
        }
        else
        {
            cin >> l >> r >> k;
            cout << query(l,r,1,n,1,k) << endl;
        }
    }
}
