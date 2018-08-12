#include<bits/stdc++.h>
using namespace std;

#define MAX          (int)2e6+5
#define ll           long long
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

struct data
{
    int l,r,idx;
    data() {}
    data(int _l,int _r,int _idx)
    {
        l = _l;
        r = _r;
        idx = _idx;
    }
};
int BLOCK_SIZE;
bool cmp(data a,data b)
{
    if(a.l/BLOCK_SIZE != b.l/BLOCK_SIZE)
        return a.l/BLOCK_SIZE < b.l/BLOCK_SIZE;
    else if((a.l/BLOCK_SIZE)&1)
        return a.r < b.r;
    return a.r > b.r;
}

ll cnt, ans[MAX];
ll n, q, a[MAX], freq[MAX];
data Q[MAX];

void add(ll x)
{
    cnt -= freq[x]*freq[x]*x;
    freq[x]++;
    cnt += freq[x]*freq[x]*x;
}
void del(ll x)
{
    cnt -= freq[x]*freq[x]*x;
    freq[x]--;
    cnt += freq[x]*freq[x]*x;
}
void MO()
{
    BLOCK_SIZE = 1200;
    sort(Q,Q+q,cmp);
    int st = 0, en = -1;
    for(int i=0; i<q; i++)
    {
        int l = Q[i].l-1 , r = Q[i].r-1 , idx = Q[i].idx;

        while(st > l)
        {
            st--;
            add(a[st]);
        }
        while(st < l)
        {
            del(a[st]);
            st++;
        }

        while(en < r)
        {
            en++;
            add(a[en]);
        }
        while(en > r)
        {
            del(a[en]);
            en--;
        }

        ans[idx] = cnt;
    }
}

int main()
{
    scanf("%I64d%I64d",&n,&q);

    for(int i=0; i<n; i++)
        scanf("%I64d",&a[i]);

    int l,r;
    for(int i=0; i<q; i++)
    {
        scanf("%d%d",&l,&r);
        Q[i] = data(l,r,i);
    }

    MO();

    for(int i=0; i<q; i++)
        printf("%I64d\n",ans[i]);
}
