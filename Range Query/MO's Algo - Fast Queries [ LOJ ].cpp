#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+5;

struct data
{
    int l,r,idx;
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

data Q[MAX];
int a[MAX] , ans[MAX] , mp[MAX];
int cnt;

void add(int x)
{
    if(!mp[x])
        cnt++;
    mp[x]++;
}
void del(int x)
{
    mp[x]--;
    if(!mp[x])
        cnt--;
}
void MO(int n,int q)
{
    BLOCK_SIZE = sqrt(n);

    sort(Q,Q+q,cmp);

    int st = 0 , en = -1;
    cnt = 0;

    for(int i=0;i<q;i++)
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

    for(int i=0;i<q;i++)
        printf("%d\n",ans[i]);
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;

        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].idx = i;
        }

        printf("Case %d:\n",cas++);
        MO(n,q);

        for(int i=0;i<MAX;i++)
            mp[i] = 0;
    }
}
