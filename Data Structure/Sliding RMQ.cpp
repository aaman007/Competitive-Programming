#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

vector<int> slidingRMQ(int a[],int n,int k)
{
    deque<int>d;
    vector<int>res;

    for(int i=0;i<n;i++)
    {
        while(!d.empty() && d.front() >= a[i])
            d.pop_front();

        d.push_front(a[i]);

        if(i>=k && a[i-k] == d.back())
            d.pop_back();

        if(i >= k-1)
            res.push_back(d.back());
    }
    return res;
}

int main()
{
    int n,k;

    cin >> n >> k;

    int a[n+2];

    for(int i=0;i<n;i++)
        cin >> a[i];

    vector<int> res = slidingRMQ(a,n,k);

    for(auto i : res)
        cout << i << " ";
    cout << endl;
}
