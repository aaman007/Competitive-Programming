#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n;
    cin >> n;
    ll a[n+2] , mx = 0 , ans;
    map < ll,ll > f;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        f[a[i]] = f[a[i]-1]+1;
        if(f[a[i]] > mx)
        {
            mx = f[a[i]];
            ans = a[i];
        }
    }
    vector < ll > v;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i] == ans)
        {
            ans--;
            v.push_back(i+1);
        }
    }
    cout << v.size() << endl;
    for(int i=v.size()-1;i>=0;i--)
        cout << v[i] << " ";
    cout << endl;
}
