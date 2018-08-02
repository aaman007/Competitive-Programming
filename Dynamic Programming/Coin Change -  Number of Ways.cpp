#include<bits/stdc++.h>
using namespace std;
const int MOD = 100000007;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int k,n;
        cin >> k >> n;
        int coin[k+2];
        for(int i=1;i<=k;i++)
            cin >> coin[i];
        int ways[n+2] = {0};
        ways[0] = 1;
        for(int i=1;i<=k;i++)      /// K = number of Coins    /// N = Amount
            for(int j=coin[i];j<=n;j++)
                    ways[j] = (ways[j]+ways[j-coin[i]])%MOD;
        cout << "Case X: " << ways[n] << endl;
    }
}

