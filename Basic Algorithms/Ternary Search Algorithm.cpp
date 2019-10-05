#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

int ternarySearch(int a[],int l,int r,int key)
{
    if(l <= r)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;

        if(a[mid1] == key)
            return mid1;
        if(a[mid2] == key)
            return mid2;

        if(key > a[mid2])
            return ternarySearch(a,mid2+1,r,key);
        else if(key < a[mid1])
            return ternarySearch(a,l,mid1-1,key);
        return ternarySearch(a,mid1+1,mid2-1,key);
    }
    return -1;
}
int main()
{
    int n;

    cin >> n;

    int a[n+2];

    for(int i=1;i<=n;i++)
        cin >> a[i];

    sort(a+1,a+n+1);

    int key;

    while(cin >> key)
    {
        if(ternarySearch(a,1,n,key) == -1)
            cout << "Value Not Found!!!\n";
        else
            cout << "Found at index : " << ternarySearch(a,1,n,key) << endl;
    }
}
