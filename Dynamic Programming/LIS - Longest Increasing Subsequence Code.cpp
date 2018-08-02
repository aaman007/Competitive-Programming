#include<bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int dp[MAX],dr[MAX],N,a[MAX];
int LIS(int u)
{
    if(dp[u]!=-1)
        return dp[u];
    int maxi = 0;
    for(int i=u+1; i<N; i++)
    {
        if(a[u]<a[i] && LIS(i)>maxi)
        {
            maxi = LIS(i);
            dr[u] = i;
        }
    }
    return dp[u] = 1+maxi;
}
void printLIS(int start)
{
    while(dr[start]!=-1)
    {
        cout << "Index : " << start+1 << "\t";
        cout << "Value : " << a[start] << endl;
        start = dr[start];
    }
    cout << "Index : " << start+1 << "\t";
    cout << "Value : " << a[start] << endl;
}
int main()
{
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> a[i];

    memset(dp,-1,sizeof(dp));
    memset(dr,-1,sizeof(dr));

    int maxLIS = 0, start = -1;

    for(int i=0; i<N; i++)
    {
        if(LIS(i)>maxLIS)
        {
            maxLIS = LIS(i);
            start = i;
        }
    }

    cout << "Size : " << maxLIS << " " << endl;
    cout << "Starting Index : " << start+1 << " " << endl;

    cout << "LIS ->\n";
    printLIS(start);
}
