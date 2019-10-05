#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e5+20;
const int LOGN = 20;

struct Info
{
    int prev , now , pos;
};

int sa[MAX] , P[LOGN][MAX] , lcp[MAX] , logn , n;
Info L[MAX];

string s;

bool cmp(Info a,Info b)
{
    if(a.prev == b.prev)
        return a.now < b.now;
    return a.prev < b.prev;
}
bool cmp2(int i,int j)
{
    return P[logn][i] < P[logn][j];
}
void buildSuffixArray()
{
    for(int i=0;i<n;i++)
        P[0][i] = s[i]-'a' , sa[i] = i;

    int gap = 1 , step = 1;

    while(gap < n)
    {
        for(int i=0;i<n;i++)
        {
            L[i].prev = P[step-1][i];
            L[i].now = (i+gap < n) ? P[step-1][i+gap] : -1;
            L[i].pos = i;
        }

        sort(L,L+n,cmp);

        for(int i=0;i<n;i++)
        {
            if(i && L[i].prev == L[i-1].prev && L[i].now == L[i-1].now)
                P[step][L[i].pos] = P[step][L[i-1].pos];
            else
                P[step][L[i].pos] = i;
        }

        step++ , gap *= 2;
    }

    logn = step-1;

    sort(sa,sa+n,cmp2);
}
void buildLCP()
{
    lcp[0] = 0;

    for(int i=1;i<n;i++)
    {
        int x = sa[i] , y = sa[i-1];

        lcp[i] = 0;

        for(int j=logn;j>=0 && x<n && y<n;j--)
        {
            if(P[j][x] == P[j][y])
            {
                lcp[i] += (1<<j);
                x += (1<<j);
                y += (1<<j);
            }
        }
    }
}
int main()
{
    cin >> s;

    n = s.size();

    buildSuffixArray();
    buildLCP();

    for(int i=0;i<n;i++)
        cout << "LCP of this suffix is : " << lcp[i] << endl;
}
