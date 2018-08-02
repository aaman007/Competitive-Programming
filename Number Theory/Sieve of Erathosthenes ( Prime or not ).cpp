#include<bits/stdc++.h>
using namespace std;
bool prime[10000005];
void sieve(int n)
{
    for(int i=2; i<n; i++)
        prime[i] = 1;
    for(int i=2; i<n; i++)
    {
        if(prime[i]==1)
        {
            for(int j=2; i*j<n; j++)
            {
                prime[i*j] = 0;
            }
        }
    }
}
int main()
{
    sieve(10000005);
    int t,n,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(prime[n])
            cout << "Is Prime\n";
        else
            cout << "Not Prime\n";
    }
    return 0;
}

