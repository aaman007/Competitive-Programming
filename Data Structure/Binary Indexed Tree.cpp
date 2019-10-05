#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 1e5+10;

int tree[MAX];

void update(int idx,int x,int n)
{
    while(idx <= n)
    {
        tree[idx] += x;
        idx += idx&(-idx);
    }
}
int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= idx&(-idx);
    }
    return sum;
}
int main()
{

}
