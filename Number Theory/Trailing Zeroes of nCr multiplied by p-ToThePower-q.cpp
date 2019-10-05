// Trailing Zeroes of nCr*p^q
//Problem : Trailing Zeroes (II)
//Link : http://lightoj.com/volume_showproblem.php?problem=1090
//Resource : https://shikhorroy.wordpress.com/2014/02/22/wp-mep2mliv-6g/
#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+10;

ll calcX(int n,int x,ll p)
{
    ll cnt = 0;

    while(n%x == 0)
    {
        cnt++;
        n /= x;
    }
    return cnt*p;
}
ll calcfactX(int n,int p)
{
    ll cnt = 0 , x = n;
    while(x/p)
    {
        cnt += x/p;
        x /= p;
    }
    return cnt;
}
int main()
{
    FastRead

    int t,n,r,p,q,cas=1;

    cin >> t;

    while(t--)
    {
        cin >> n >> r >> p >> q;

        ll c1 = calcX(p,2,q) , c2 = calcX(p,5,q);

        ll c3 = calcfactX(n,2)-calcfactX(r,2)-calcfactX(n-r,2) , c4 = calcfactX(n,5)-calcfactX(r,5)-calcfactX(n-r,5) ;

        cout << "Case " << cas++ << ": " << min(c1+c3,c2+c4) << endl;
    }
}
