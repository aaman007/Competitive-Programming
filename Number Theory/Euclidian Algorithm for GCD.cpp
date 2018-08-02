/// Euclidian Algorithm for GCD
/// Code is below :

#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,rem;
    cin >> a >> b;
    while(b>0)
    {
        rem = a%b;
        a = b;
        b = rem;
    }
    cout << a << endl;
}

/// Or

#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
    long long rem;
    while(b>0)
    {
        rem = a%b;
        a = b;
        b = rem;
    }
    return a;
}
int main()
{
    long long int a,b,rem;
    cin >> a >> b;
    cout << gcd(a,b) << endl;
}

/// You can also find gcd in c++ just like this :
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b;
    cin >> a >> b;
    cout << __gcd(a,b) << endl;
}
///__gcd(num1,num2) returns the gcd
