
#include<bits/stdc++.h>
using namespace std;
class DSU
{
    public :
        int par[260], sum[260], N, k;

        void init()
        {
            for(int i=0; i<260; i++)
            {
                par[i] = i;
                sum[i] = 1;
            }
        }
        int Find(int n)
        {
            if(par[n] == n)
                return n;
            return par[n] = Find(par[n]);
        }
        void Union(int n)
        {
            Find(n);
            if(par[n] == 0)
                return;
            int m = Find(par[n]-1);
            if(sum[par[n]]+sum[m] <= k)
            {
                sum[m] += sum[par[n]];
                sum[par[n]] += sum[m];
                par[n] = m;
                Union(m);
            }
        }
};

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    DSU ob;

    cin >> ob.N >> ob.k;

    ob.init();

    int a;
    for(int i=0;i<ob.N;i++)
    {
        cin >> a;
        ob.Union(a);
        cout << ob.Find(ob.par[a]) << " ";
    }
    cout << endl;
}
