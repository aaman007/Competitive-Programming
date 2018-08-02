/// Code for finding square root of a number :
#include<bits/stdc++.h>
using namespace std;
double Sqrt(int n)
{
    double high = (double)n , low = 0.0 , mid;
    while(high-low > 0.000001)
    {
        mid = (high+low)/2.0;
        if(mid*mid > n)
            high = mid;
        else if(mid*mid < n)
            low = mid;
    }
    return mid;
}
int main()
{
    int n;
    cin >> n;
    cout << Sqrt(n) << endl;
}
