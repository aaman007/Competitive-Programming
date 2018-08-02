#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector < int > primes;
const int MAX = 1000005;
bool prime[MAX];
void sieve(int n)
{
    for(int i=2; i<=n; i++)
        prime[i] = 1;
    for(int i=2; i<=n; i++)
    {
        if(prime[i]==1)
        {
            primes.push_back(i);
            for(int j=2; i*j<=n; j++)
                prime[i*j] = 0;
        }
    }
}
int bigMod(int a,int b,int M)
{
    if(b==0)
        return 1;
    ll x = bigMod(a,b/2,M);
    x = (x*x)%M;
    if(b&1)
        x = (x*a)%M;
    return x;
}
int largestPower(int n,int p)
{
    int cnt = 0;
    while(n)
    {
        n /= p;
        cnt += n;
    }
    return cnt;
}
int fact(int n,int p)
{
    int res = 1;
    for(int i=0;primes[i]<=n;i++)
    {
        int k = largestPower(n,primes[i]);
        res = (res*bigMod(primes[i],k,p))%p;
    }
    return res;
}
int main()
{
    sieve(MAX);
    int n,p;
    while(cin >> n >> p)
    {
        cout << fact(n,p) << endl;
    }
    return 0;
}
