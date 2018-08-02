#include<bits/stdc++.h>
using namespace std;

#define ll          long long
#define FastRead    ios_base::sync_with_stdio(false);cin.tie(NULL);
bool Check(int n,int pos)
{
    return (n & (1<<pos));
}
int Set(int n,int pos)
{
    return (n | (1<<pos));
}
int w[20][20],n;
int dp[(1<<20)+2];
int call(int mask)
{
    if(mask == (1<<n)-1)
        return 0;
    else if(dp[mask] != -1)
        return dp[mask];
    int &ret = dp[mask];
    int ans = 1<<28;
    for(int i=0;i<n;i++)
    {
        if(!Check(mask,i))
        {
            int price = w[i][i];
            for(int j=0;j<n;j++)
            {
                if(Check(mask,j))
                    price += w[i][j];
            }
            price += call(Set(mask,i));
            ans = min(ans,price);
        }
    }
    return dp[mask] = ans;
}
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> w[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout << call(0) << endl;
}
