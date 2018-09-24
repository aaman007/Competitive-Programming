#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6+5;
const int realMOD = 1000003;
const int MOD = 1e6+3;

ll f[MAX] , inv[MAX];
ll bigMod(int a,int b)
{
    if(b == 0)
        return 1;
    ll x = bigMod(a,b/2);
    x = (x*x)%MOD;
    if(b&1)
        x = (x*a)%MOD;
    return x;
}
ll nCr(int n,int r)
{
    ll x = (f[r]*f[n-r])%MOD;
    x = (f[n]*bigMod(x,MOD-2))%MOD;
    return x;
}
int main()
{
    f[0] = 1;
    for(int i=1;i<MAX;i++)
        f[i] = (i*1LL*f[i-1])%MOD;
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        printf("Case %d: %lld\n",cas++,nCr(n,k));
    }
}
