#include<bits/stdc++.h>

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

#define LL long long
#define MX 50005

using namespace std;

int main()
{
    int t, n , q , l , r , cas = 1;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d%d",&n,&q);

        map<int,int>cum;
        int mx = 0 , ans[q+2];

        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&l,&r);
            cum[l]++;
            cum[r+1]--;
        }

        for(int i=0;i<q;i++)
        {
            scanf("%d",&ans[i]);
            cum[ans[i]] += 0;
        }

        int sum = 0;
        for(auto &i : cum)
        {
            sum += i.second;
            i.second = sum;
        }

        printf("Case %d:\n",cas++);
        for(int i=0;i<q;i++)
            printf("%d\n",cum[ans[i]]);
    }
}
