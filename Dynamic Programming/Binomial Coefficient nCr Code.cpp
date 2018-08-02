#include <bits/stdc++.h>
using namespace std;
int dp[700][700];
int nCr(int n,int r)
{
    if(r==n)
        return 1;
    else if(r==1)
        return n;
    if(dp[n][r] != -1)
        return dp[n][r];
    else
        return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}
int main()
{
    int n,r;
    memset(dp,-1,sizeof(dp));
    cin >> n >> r;
    cout << nCr(n,r) << endl;
}
