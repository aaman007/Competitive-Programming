#include<bits/stdc++.h>
#define ll long long
using namespace std;
int bigMod(int a,int b,int M)
{
    if(b==0)
        return 1;
    ll x = bigMod(a,b/2,M);
    x = (x*x)%M;
    if(b&1)
        x = (x*a)%M;
    return x;
}
int main()
{
    ll b,p,m;
    while(cin >> b >> p >> m)
    {
        cout << bigMod(b,p,m) << endl;
    }
}
