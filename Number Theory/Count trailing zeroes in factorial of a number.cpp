
/// Counting how many trailing zeroes are of ( N ! ) :
#include<bits/stdc++.h>
using namespace std;
#define ll           long long
int trailingZeroes(int n)
{
    int cnt = 0 , f = 5;
    while(f <= n)
    {
        cnt += n/f;
        f *= 5;
    }
    return cnt;
}
int main()
{
    int n;
    while(cin >> n)
    {
        cout << trailingZeroes(n) << endl;
    }
}

/// Smallest number N such that , factorial of N ends with exactly x zeroes :
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll counter(ll p)
{
    ll cnt = 0, f = 5;
    while (f <= p)
    {
        cnt += p/f;
        f *= 5;
    }
    return cnt;
}
ll findNum(ll n)
{
    if(n==1)
        return 5;
    int st = 0;
    int en = 5*n;
    ll ans = -1;
    while (st <= en)
    {
        int mid = (st+en)/2;
        ll x = counter(mid);
        if(x == n)
        {
            ans = mid;
            en = mid-1;
        }
        else if(x > n)
            en = mid-1;
        else
            st = mid+1;
    }
    return ans;
}
int main()
{
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = findNum(n);
        cout << "Case " << cas++ << ": ";
        if(ans>=0)
            cout << ans << endl;
        else
            cout << "Go Home! You are drunk!\n";
    }
}
