//Source of learning : https://forthright48.com/prime-factorization-of-factorial/
//
//Problem : Intelligent Factorial Factorization
//Link : http://lightoj.com/volume_showproblem.php?problem=1035
#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

bool prime[MAX];
vector<int>primes;
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
vector<pii> factorialPrimeFact(int n)
{
    vector<pii> ans;

    for(int i=0; i<primes.size() && primes[i]<=n; i++)
    {
        int cnt = 0, p = primes[i] , x = n;
        while(x/p)
        {
            cnt += x/p;
            x /= p;
        }
        if(cnt)
            ans.push_back({primes[i],cnt});
    }
    return ans;
}
void solve(int n)
{
    vector<pii> ans = factorialPrimeFact(n);

    cout << n << " = ";
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            cout << " * ";
        cout << ans[i].first << " (" << ans[i].second << ")";
    }
    cout << endl;
}
int main()
{
    FastRead

    sieve();

    int t,n,cas=1;

    cin >> t;

    while(t--)
    {
        cin >> n;

        cout << "Case " << cas++ << ": ";

        solve(n);
    }
}
