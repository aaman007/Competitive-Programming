//Problem : A New Function
//Link : http://lightoj.com/volume_showproblem.php?problem=1098

#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

ll solve(int n)
{
    int sq = sqrt(n);
    ll sum = 0;

    for(int i=2;i<=sq;i++)
    {
        int j = n/i;
        sum += (j+i)*1LL*(j-i+1)/2;
        sum += (j-i)*1LL*i;
    }
    return sum;
}
int main()
{
    FastRead

    int t,n,cas=1;

    cin >> t;

    while(t--)
    {
        cin >> n;

        cout << "Case " << cas++ << ": " << solve(n) << endl;
    }
}
