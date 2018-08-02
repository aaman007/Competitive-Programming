#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool Check(ll n,ll pos) { return (n & (1<<pos)); }
bool Set(ll &n,ll pos) { return n = n | (1<<pos); }
bool Clear(ll &n,ll pos) { return n = n & ~(1<<pos); }
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
    for(int i=29;i>=0;i--)
    {
        if(Check(n,i))
        {
            if(cur->one == NULL)
                cur->one = new trieNode();
            cur = cur->one;
        }
        else
        {
            if(cur->zero == NULL)
                cur->zero = new trieNode();
            cur = cur->zero;
        }
        cur->cnt++;
    }
}
ll MinimumXor(ll n)
{
    trieNode *cur = root;
    for(int i=29;i>=0;i--)
    {
        if(Check(n,i))
        {
            if(cur->one && cur->one->cnt)
            {
                Clear(n,i);
                cur = cur->one;
            }
            else
                cur = cur->zero;
        }
        else
        {
            if(cur->zero && cur->zero->cnt)
                cur = cur->zero;
            else
            {
                Set(n,i);
                cur = cur->one;
            }
        }
        cur->cnt--;
    }
    return n;
}
int main()
{
    FastRead
    root = new trieNode();
    int n;
    cin >> n;
    ll a[n+2] , p;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        cin >> p;
        Insert(p);
    }
    for(int i=0;i<n;i++)
        cout << MinimumXor(a[i]) << " ";
    cout << endl;
}
