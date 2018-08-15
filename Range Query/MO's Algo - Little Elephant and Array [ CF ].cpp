#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e9+7
#define MAX          (int)1e5+5
#define ll           long long
#define pii          pair<ll,ll>
#define sf(a)        scanf("%d",&a)
#define pf(a)        printf("%d\n",a)
#define bug(a)       cerr << #a << " : " << a << endl;
#define mem(a,b)     memset(a,b,sizeof(a))
#define all(x)       x.begin(),x.end()
#define rall(x)      x.rbegin(),x.rend()
#define pb           push_back
#define F            first
#define S            second
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

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

int n,m,a[MAX],ans[MAX],cnt;
data Q[MAX];

unordered_map<int,int>mp;
void add(int x)
{
    mp[x]++;
    if(mp[x] == x)
        cnt++;
    else if(mp[x] == x+1)
        cnt--;
}
void del(int x)
{
    if(mp[x] == x)
        cnt--;
    mp[x]--;
    if(mp[x] == x)
        cnt++;
}
void MO()
{
    BLOCK_SIZE = 1000;
    sort(Q,Q+m,cmp);

    int st = 0 , en = -1;
    for(int i=0;i<m;i++)
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
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].idx = i;
    }

    MO();

    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
}
