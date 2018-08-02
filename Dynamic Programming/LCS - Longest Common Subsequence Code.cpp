#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
string s,s1,ans;
int LCS(int i,int j)
{
    if(s[i]=='\0' || s1[j]=='\0')
        return 0;
    else if(dp[i][j] != -1)
        return dp[i][j];
    int len1=0,len2=0,mx=0;
    if(s[i]==s1[j])
        len1 = 1 + LCS(i+1,j+1);
    else
    {
        len1 = LCS(i+1,j);
        len2 = LCS(i,j+1);
    }
    return  dp[i][j] = max(len1,len2);
}
void findLCS(int i,int j)
{
    if(s[i]=='\0' || s1[j]=='\0')
    {
        cout << ans << endl;
        return;
    }
    if(s[i]==s1[j])
    {
        ans += s[i];
        findLCS(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1])
            findLCS(i+1,j);
        else
            findLCS(i,j+1);
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> s >> s1;
    cout << LCS(0,0) << endl;
    ans = "";
    findLCS(0,0);
}
