#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector < ll > primes;
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
ll factorialDivisors(ll n)
{
    ll res = 1;
    for(int i=0;primes[i]<=n;i++)
    {
        ll exp = 0;
        ll p = primes[i];
        while(p <= n)
        {
            exp += (n/p);
            p *= primes[i];
        }
        res *= (exp+1);
    }
    return res;
}
int main()
{
    sieve(MAX);
    ll n;
    while(cin >> n)
    {
        cout << factorialDivisors(n) << endl;
    }
    return 0;
}
