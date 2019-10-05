#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

int josephus(int n,int k)
{
    if(n == 1)
        return 1;

    return (josephus(n-1,k)+k-1)%n + 1;
}
int main()
{
    FastRead

    int n,k;
    cin >> n >> k;
    cout <<  josephus(n,k) << endl;
}
