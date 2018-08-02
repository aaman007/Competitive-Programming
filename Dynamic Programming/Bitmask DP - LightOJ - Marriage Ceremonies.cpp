#include<bits/stdc++.h>
using namespace std;

#define MOD         1e9+7
#define MAX         1e5+5
#define ll          long long
#define pii         pair<ll,ll>
#define sf(a)       scanf("%d",&a)
#define pf(a)       printf("%d\n",a)
#define bug(a)      cout << "  " << endl;
#define mem(a,b)    memset(a,b,sizeof(a))
#define all(x)      x.begin(),x.end()
#define rall(x)     x.rbegin(),x.rend()
#define pb          push_back
#define F           first
#define S           second
#define Time()      cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead    ios_base::sync_with_stdio(false);cin.tie(NULL);

#define Check(n,pos)((1<<pos)&n)
#define Set(n,pos)  (n|(1<<pos))

int n,p[18][18],dp[1<<17];
int call(int mask,int i)
{
    int &ret = dp[mask];
    if(i == n)
        return 0;
    else if(ret != -1)
        return ret;
    ret = 0;
    for(int j=0;j<n;j++)
    {
        if(!Check(mask,j))
            ret = max(ret,p[i][j]+call(Set(mask,j),i+1));
    }
    return ret;
}
int main()
{
    int tc,cas=1;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> p[i][j];
        memset(dp,-1,sizeof dp);
        cout << "Case " << cas++ << ": " << call(0,0) << endl;;
    }
}
