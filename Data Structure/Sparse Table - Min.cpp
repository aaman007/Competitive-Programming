#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 505;

int P[MAX][20];

void buildSparseTable(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
        P[i][0] = arr[i];

    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 1; (i + (1 << j) - 1) <= n; i++)
            P[i][j] = min(P[i][j - 1] , P[i + (1 << (j - 1))][j - 1]);
    }
}
int query(int L, int R)
{
    int log = log2(R - L + 1);

    return min(P[L][log] , P[R - (1 << log) + 1][log]);
}

int main()
{
    int t,cas=1;

    cin >> t;

    while(t--)
    {
        int n,q,u,v;

        cin >> n >> q;

        int a[n+2];

        for(int i=1;i<=n;i++)
            cin >> a[i];

        buildSparseTable(a,n);

        while(q--)
        {
            cin >> u >> v;

            cout << query(u,v) << endl;
        }
    }
}
