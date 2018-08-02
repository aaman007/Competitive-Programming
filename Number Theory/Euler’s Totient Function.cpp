#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int phi[MAX],mark[MAX];
void totient()
{
    /// Initializing
    for(int i=1;i<=MAX;i++)
        phi[i] = i;
    /// 1 is not prime
    mark[1] = 1;
    /// Finding all number's phi
    for(int i=2;i<=MAX;i++)
    {
        if(!mark[i])           /// If i is prime
        {
            for(int j=i;j<=MAX;j+=i)
            {
                mark[j] = 1;    /// Marking j as not prime
                phi[j] = phi[j]/i*(i-1);  /// Formula phi(p) = p/n * (n-1) where n is p's prime divisor
            }
        }
    }
}
int main()
{
    totient();
    int x;
    while(cin >> x)
    {
        cout << phi[x] << endl;
    }
}
