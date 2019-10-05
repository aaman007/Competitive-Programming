//Resource : http://nstu-coding-planet.blogspot.com/2017/07/lightoj-1054-efficient-pseudo-code.html
//
//
//Problem Name : Efficient Pseudo Code
//Problem Link : http://lightoj.com/volume_showproblem.php?problem=1054
//Solution :
#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;
const int MOD = 1e9+7;

bool prime[MAX];
vector<int>primes;

ll bigMod(ll a,ll b,ll M)
{
    if(b==0)
        return 1;
    ll x = bigMod(a,b/2,M);
    x = (x*x)%M;
    if(b&1)
        x = (x*a)%M;
    return x;
}
void sieve()
{
    fill(prime,prime+MAX,1);

    prime[2] = 1;
    primes.push_back(2);
    for(int i=4; i<MAX; i+=2)
        prime[i] = 0;
    for(int i=3; i<MAX; i+=2)
    {
        if(prime[i])
        {
            primes.push_back(i);
            for(int j=i+i; j<MAX; j+=i)
                prime[j] = 0;
        }
    }
}
ll primeFact(ll n,int m)
{
    ll sum = 1;

    for(int i=0; i<primes.size() && primes[i]<=n; i++)
    {
        ll cnt = 0, p = primes[i];

        if(n%p == 0)
        {
            while(n%p == 0)
                cnt++ , n /= p;

            cnt = cnt*m+1;

            ll calc = (bigMod(p,cnt,MOD)+MOD-1)%MOD;
            calc *= bigMod(p-1,MOD-2,MOD);
            calc %= MOD;

            sum = (sum*calc)%MOD;

        }
    }
    if(n > 1)
    {
        ll calc = (bigMod(n,1+m,MOD)+MOD-1)%MOD;
        calc *= bigMod(n-1,MOD-2,MOD);
        calc %= MOD;

        sum = (sum*calc)%MOD;
    }

    return sum;
}
int main()
{
    FastRead

    sieve();

    int t,cas=1;

    cin >> t;

    while(t--)
    {
        int n,m;

        cin >> n >> m;

        cout << "Case " << cas++ << ": " << primeFact(n,m) << endl;
    }
}
