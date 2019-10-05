#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll dp[22][5][2];
ll DP(int cur,int cnt,string &s,bool f)
{
    if(cur == s.size())
        return (cnt <= 3);
    else if(cnt > 3)
        return 0;

    ll &ret = dp[cur][cnt][f];
    if(ret != -1)
        return ret;
    ret = 0;

    int lim = (f ? 9 : s[cur]-'0');

    for(int i=0;i<=lim;i++)
        ret += DP(cur+1 , cnt+(i>0) , s , f | (i<lim));

    return ret;
}
string converted(string s)
{
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i] != '0')
        {
            s[i]--;
            return s;
        }
        s[i] = '9';
    }
}
int main()
{
    FastRead

    int t;
    cin >> t;

    string l,r;

    while(t--)
    {
        cin >> l >> r;
        l = converted(l);

        memset(dp,-1,sizeof dp);
        ll ret = DP(0,0,r,0);
        memset(dp,-1,sizeof dp);
        cout << ret-DP(0,0,l,0) << endl;
    }
}
