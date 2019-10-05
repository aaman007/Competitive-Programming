#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 2e6+10;

string S;
int z[MAX];

void zFunction()
{
    int left, right;
    left = right = z[0] = 0;

    for(int i=1; i<S.size(); i++)
    {
        if(i <= right)
            z[i] = min(z[i-left],right-i+1);

        while(i+z[i] < S.size() && S[i+z[i]] == S[z[i]])
            z[i]++;

        if(i+z[i]-1 > right)
            left = i, right = i+z[i]-1;
    }
}
bool isSubstr(string t,string p)
{
    S = p + "#" + t;
    zFunction();

    for(int i=p.size()+1; i<S.size(); i++)
    {
        if(z[i] == p.size())
            return true;
    }
    return false;
}
int countSubstr(string t,string p)
{
    S = p + "#" + t;
    memset(z,0,sizeof z);
    zFunction();

    int cnt = 0;
    for(int i=p.size()+1; i<S.size(); i++)
    {
        if(z[i] == p.size())
            cnt++;
    }
    return cnt;
}
int countNonOverlappingSubstr(string t,string p)
{
    S = p + "#" + t;
    memset(z,0,sizeof z);
    zFunction();

    int cnt = 0;
    for(int i=p.size()+1; i<S.size(); i++)
    {
        if(z[i] == p.size())
            cnt++ , i = i+z[i]-1;
    }
    return cnt;
}
int main()
{
    string txt,p;

    cin >> txt >> p;

    cout << countNonOverlappingSubstr(txt,p) << endl;
}
