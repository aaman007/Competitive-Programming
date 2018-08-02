#include<bits/stdc++.h>
using namespace std;
#define ll           long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll dp[35][35] , dp2[35][35][70];
string s,s1,ans;
ll LCS(int i,int j)
{
    if(s[i]=='\0')
        return s1.size()-j;
    else if(s1[j] == '\0')
        return s.size()-i;
    else if(dp[i][j] != -1)
        return dp[i][j];

    ll &ret = dp[i][j];

    if(s[i]==s1[j])
        return ret = 1 + LCS(i+1,j+1);
    return  ret = 1 + min(LCS(i,j+1),LCS(i+1,j));
}
ll findWays(int i,int j,int len)
{
    if(s[i] == '\0' && s1[j] == '\0' && !len)
        return 1;
    else if(s[i] == '\0' && s1[j] == '\0')
        return 0;

    ll &ret = dp2[i][j][len];
    if(ret != -1)
        return ret;

    if(s[i] == '\0')
        ret = findWays(i,j+1,len-1);
    else if(s1[j] == '\0')
        ret = findWays(i+1,j,len-1);
    else if(s[i] == s1[j])
        ret = findWays(i+1,j+1,len-1);
    else
        ret = findWays(i+1,j,len-1)+findWays(i,j+1,len-1);
    return ret;
}
int main()
{
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        cin >> s >> s1;

        memset(dp,-1,sizeof dp);
        ll len =  LCS(0,0);

        memset(dp2,-1,sizeof dp2);

        cout << "Case " << cas++ << ": " << len << " " << findWays(0,0,len) << endl;
    }
}
