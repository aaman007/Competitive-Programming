#include<bits/stdc++.h>
using namespace std;
int dp[10][105] , coin[105] , N;
int coinChange(int i,int amount)
{
    if(i==N)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    else if(dp[i][amount]!=-1)
        return dp[i][amount];
    int p1 = 0 , p2 = 0;
    if(amount-coin[i]>=0)
        p1 = coinChange(i,amount-coin[i]);
    p2 = coinChange(i+1,amount);

    return dp[i][amount] = p1|p2;
}
int main()
{
    int Money;
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> coin[i];
    memset(dp,-1,sizeof(dp));
    while(cin >> Money)
    {
        cout << coinChange(0,Money) << endl;
    }
}
