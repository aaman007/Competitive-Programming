#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005],wieght[1005],cost[1005] , CAP , N;
int knapsack(int i,int w)
{
    if(i==N)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int profit1=0,profit2=0;
    if(w+wieght[i]<=CAP)
        profit1 = cost[i]+knapsack(i+1,w+wieght[i]);
    profit2 = knapsack(i+1,w);
    return dp[i][w] = max(profit1,profit2);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin >> N >> CAP;
        for(int i=0;i<N;i++)
            cin >> wieght[i] >> cost[i];
        cout << knapsack(0,0) << endl;
    }
}
