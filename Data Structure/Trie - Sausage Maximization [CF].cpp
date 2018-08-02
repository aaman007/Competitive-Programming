#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool Check(ll n,ll pos) { return (n>>pos)&1; }
struct trieNode
{
    trieNode *one,*zero;
    int cnt;
    trieNode()
    {
        one = zero = NULL;
        cnt = 0;
    }
};
trieNode *root;
void Insert(ll n)
{
    trieNode *cur = root;
    for(ll i=50;i>=0;i--)
    {
        if(Check(n,i))
        {
            if(!cur->one)
                cur->one = new trieNode();
            cur = cur->one;
        }
        else
        {
            if(!cur->zero)
                cur->zero = new trieNode();
            cur = cur->zero;
        }
        cur->cnt++;
    }
}
ll MaximumXor(ll n)
{
    trieNode *cur = root;
    ll ret = 0;
    for(ll i=50;i>=0;i--)
    {
        if(Check(n,i))
        {
            if(cur->zero && cur->zero->cnt)
            {
                ret += (1LL<<i);
                cur = cur->zero;
            }
            else
                cur = cur->one;
        }
        else
        {
            if(cur->one && cur->one->cnt)
            {
                ret += (1LL<<i);
                cur = cur->one;
            }
            else
                cur = cur->zero;
        }
    }
    return ret;
}
int main()
{
    FastRead
    int n;
    cin >> n;
    root = new trieNode();
    ll a[n+2],Max=0,suff=0,pref=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        suff ^= a[i];
    }
    Insert(0);
    for(int i=0;i<n;i++)
    {
        suff ^= a[i];
        pref ^= a[i];
        Insert(pref);
        Max = max(Max,MaximumXor(suff));
    }
    cout << Max << endl;
}
