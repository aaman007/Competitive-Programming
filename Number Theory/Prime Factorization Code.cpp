#include<bits/stdc++.h>
using namespace std;
vector < int > v;
void primeFact(int n)
{
    while(n%2==0 && n>0)
    {
        v.push_back(2);
        n /= 2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0 && n>0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if(n>2)
        v.push_back(n);
}
int main()
{
    int n;
    while(cin >> n)
    {
        v.clear();
        int k = n;
        if(n == 0)
            break;
        if(n<0)
            v.push_back(-1) , n *= -1;
        primeFact(n);
        cout << k << " = ";
        for(int i=0;i<v.size();i++)
        {
            cout << v[i];
            if(i == v.size()-1)
            {
                cout << endl;
                break;
            }
            cout << " x ";
        }
    }
}
