#include<bits/stdc++.h>
using namespace std;
#define all(s)              s.begin(),s.end()
#define ll                  long long
#define FastRead            ios_base::sync_with_stdio(false);cin.tie(NULL);

#define Check(n,pos)  (n & (1<<pos))
#define Set(n,pos)    (n | (1<<pos))

string s;
int n,mod;
ll dp[(1<<18)+2][102] , End;
ll call(ll mask,ll val)
{
    if(mask == End)
    {
        if(val)
            return 0;
        else
            return 1;
    }
    ll &ret = dp[mask][val];
    if(ret != -1)
        return ret;
    ret = 0;
    for(int i=0;i<n;i++)
    {
        int digit = s[i]-'0';
        if(Check(mask,i) || (i > 0 && !Check(mask,i-1) && s[i-1] == s[i]) || (!mask && !digit))
                continue;
        ret += call(Set(mask,i), (val * 10 + digit) % mod);
    }
    return ret;
}
int main()
{
    FastRead
    cin >> s >> mod;
    n = s.size();
    End = (1<<n)-1;
    memset(dp,-1,sizeof dp);
    sort(all(s));
    cout << call(0,0) << endl;
}
