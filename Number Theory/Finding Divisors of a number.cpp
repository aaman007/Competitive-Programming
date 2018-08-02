/// Code for Finding Number of divisors and then printing them :

#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
vector < int > divisors[MAX];
void Divisors(int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=i; j<n; j+=i)
        {
            divisors[j].push_back(i);
        }
    }
}
int main()
{
    Divisors(MAX);
    int x;
    while(cin >> x)
    {
        cout << "Number of Divisors of X is : " << divisors[x].size() << endl;
        cout << "The Divisors are :\n";
        for(int i=0; i<divisors[x].size(); i++)
            cout << divisors[x][i] << " ";
        cout << endl;
    }
}


/// Code for Sum of Divisors ( SOD ) :

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
long long sod[MAX];
void SOD(int n)    ///SOD = Sum of Divisors
{
    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j+=i)
        {
            sod[j] += i;
        }
    }
}
int main()
{
    SOD(MAX);
    int x;
    while(cin >> x)
    {
        cout << "Sum of Divisors of X is : " << sod[x] << endl;
    }
}



/// Code for Number of Divisors ( NOD ) :

#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
long long nod[MAX];
void NOD(int n)    ///NOD = Number of Divisors
{
    for(int i=1; i<n; i++)
    {
        for(int j=i; j<n; j+=i)
        {
            nod[j]++;
        }
    }
}
int main()
{
    NOD(MAX);
    int x;
    while(cin >> x)
    {
        cout << "Number of Divisors of X is : " << nod[x] << endl;
    }
}


/// Sum of Divisors of numbers in range A to B :

#include<bits/stdc++.h>
using namespace std;

#define ll          unsigned long long
#define FastRead    ios_base::sync_with_stdio(false);cin.tie(NULL);
ll super(ll n)
{
    if(n&1)
        return n*((n+1)>>1);
    else
        return (n>>1)*(n+1);
}
ll divisorSum(ll n)
{
    ll sum = 0 , lim = sqrt(n) , x = super(lim);
    for (ll i = 1; i <= lim; i++)
    {
        sum += (n/i)*i;
        if(i*i != n)
        {
            sum += super(n/i);
            sum -= x;
        }
    }
    return sum;
}
int main()
{
    FastRead
    ll a,b,sum;
    cin >> a >> b;
    sum = divisorSum(b)-divisorSum(a-1);
    cout << sum << endl;
}


///Problem : Divisors
///Link : http://codeforces.com/contest/987/problem/D
///Solution :

#include<bits/stdc++.h>
using namespace std;
#define ll           unsigned long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

int main();
vector < ll > ans;
map < ll,vector<ll> > dp;
ll x,k;
void divisors(ll n,ll cnt)
{
    if(ans.size() == 1e5)
        return;
    if(cnt == k || n == 1)
    {
        ans.push_back(n);
        return;
    }
    else if(dp[n].size())
    {
        for(auto i : dp[n])
            divisors(i,cnt+1);
        return;
    }
    int lim = sqrt(n);
    vector < ll > d;
    for(int i=1;i<=lim;i++)
    {
        if(n%i == 0)
        {
            dp[n].push_back(i);
            divisors(i,cnt+1);
            if(n/i > lim)
                d.push_back(n/i);
        }
    }
    reverse(begin(d),end(d));
    for(auto i : d)
    {
        dp[n].push_back(i);
        divisors(i,cnt+1);
    }
}
int main()
{
    FastRead
    cin >> x >> k;
    divisors(x,0);
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
}
