#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool Check(int N,int pos){ return (bool)(N & (1<<pos));}
void Set(int &N,int pos){ N=N | (1<<pos);}
const int MAX = 1e8+5;
int prime[(MAX>>5)+2];
vector < ll > primes;
void sieve()
{
    int lim = sqrt(MAX);
    for(int i=3; i<=lim; i+=2)
    {
        if(!Check(prime[i>>5],i&31))
        {
            for(int j=i*i; j<=MAX; j+=(i<<1))
            {
                Set(prime[j>>5],j&31);
            }
        }
    }
    primes.push_back(0);
    primes.push_back(2);
    int last = 1;
    for(int i=3; i<=MAX; i+=2)
    {
        if(!Check(prime[i>>5],i&31))
        {
            primes.push_back(i+primes[last]);
            last++;
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    while(n--)
    {
        int x,y;
        cin >> x >> y;
        cout << primes[y]-primes[x-1] << endl;
    }
}
