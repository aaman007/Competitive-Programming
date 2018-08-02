#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
string s,s1,ans;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin >> s >> s1;
        int len1 = s.length() , len2 = s1.length();
        for(int i=0;i<=len1;i++)
            dp[i][0] = i;
        for(int i=0;i<=len1;i++)
            dp[0][i] = i;
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(s[i-1]==s1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
        cout << dp[len1][len2] << endl;
    }
}
