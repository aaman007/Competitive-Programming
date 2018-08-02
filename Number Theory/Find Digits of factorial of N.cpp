#include<bits/stdc++.h>
using namespace std;

#define ll          long long
int findDigits(int n)
{
    if(n<=1)
        return n;
    double digits = 0;
    for(int i=2;i<=n;i++)
        digits += log10(i);
    return floor(digits)+1;
}
int main()
{
    int n;
    while(cin >> n)
    {
        cout << findDigits(n) << endl;
    }
}
