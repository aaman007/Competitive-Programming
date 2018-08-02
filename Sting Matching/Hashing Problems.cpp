/**
Problem : Watto and Mechanism
Link : http://codeforces.com/contest/514/problem/C
Solution with Single Hash :
**/
#include<bits/stdc++.h>
using namespace std;

#define ll           unsigned long long
#define MOD          (ll)1e9+7
#define MAX          (ll)1e6+5
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll save[MAX];
ll prime = 313;
void pre()
{
    save[0] = 1;
    for(ll i=1; i<MAX; i++)
        save[i] = (save[i-1]*prime)%MOD;
}
ll getHash(string s)
{
    ll hashValue = 0;
    for(ll i=0; i<s.size(); i++)
        hashValue += s[i]*save[i];
    return hashValue;
}
ll a[MAX], idx;

bool test(ll hashValue,char ch,ll i)
{
    hashValue += ch*save[i];
    if(binary_search(a,a+idx,hashValue))
        return true;
    return false;
}
bool checkHash(string s)
{
    ll hashValue = getHash(s) , x;

    for(ll i=0; i<s.size(); i++)
    {
        x = hashValue - s[i]*save[i];

        for(char ch = 'a' ; ch <= 'c' ; ch++)
        {
            if(s[i] != ch && test(x,ch,i))
                return true;
        }
    }
    return false;
}
int main()
{
    FastRead
    ll n,m;
    cin >> n >> m;
    pre();
    string s;
    for(ll i=0; i<n; i++)
    {
        cin >> s;
        a[idx++] = getHash(s);
    }

    sort(a,a+idx);

    while(m--)
    {
        cin >> s;
        if(checkHash(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

/// Solution with Double Hash :
#include<bits/stdc++.h>
using namespace std;

#define ll           unsigned long long
#define MOD          (ll)1e15+7
#define MOD2         (ll)6e15+9
#define MAX          (ll)1e6+5
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll save[MAX], save2[MAX];
ll prime = 113, prime2 = 257;
void pre()
{
    save[0] = 1;
    save2[0] = 1;
    for(ll i=1; i<MAX; i++)
    {
        save[i] = (save[i-1]*prime)%MOD;
        save2[i] = (save2[i-1]*prime2)%MOD2;
    }
}
ll getHash(string s)
{
    ll hashValue = 0;
    for(ll i=0; i<s.size(); i++)
        hashValue += s[i]*save[i];

    return hashValue;
}
ll getHash2(string s)
{
    ll hashValue = 0;
    for(ll i=0; i<s.size(); i++)
        hashValue += s[i]*save2[i];

    return hashValue;
}

ll a[MAX], a2[MAX], idx;

bool test(ll hashValue,ll hashValue2,char ch,ll i)
{
    hashValue += ch*save[i];
    hashValue2 += ch*save2[i];

    if(binary_search(a,a+idx,hashValue) && binary_search(a2,a2+idx,hashValue2))
        return true;
    return false;
}
bool checkHash(string s)
{
    ll hashValue = getHash(s) , hashValue2 = getHash2(s);

    for(ll i=0; i<s.size(); i++)
    {
        hashValue -= s[i]*save[i];
        hashValue2 -= s[i]*save2[i];

        for(char ch = 'a' ; ch <= 'c' ; ch++)
        {
            if(s[i] != ch && test(hashValue,hashValue2,ch,i))
                return true;
        }

        hashValue += s[i]*save[i];
        hashValue2 += s[i]*save2[i];
    }
    return false;
}
int main()
{
    FastRead
    ll n,m;
    cin >> n >> m;
    pre();
    string s;
    for(ll i=0; i<n; i++)
    {
        cin >> s;
        a[idx++] = getHash(s);
        a2[idx-1] = getHash2(s);
    }

    sort(a,a+idx);
    sort(a2,a2+idx);

    while(m--)
    {
        cin >> s;
        if(checkHash(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}


/**
Problem : Good Substrings
Link : http://codeforces.com/contest/271/problem/D
Solution 1 :
**/
#include<bits/stdc++.h>
using namespace std;
#define ll           unsigned long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 2e3+5;

ll save[MAX];
ll base = 73939133;

unordered_map < ll,bool > mp;
map < char,bool > check;
string Mem = "abcdefghijklmnopqrstuvwxyz";

ll getHash(string s,int k,int idx)
{
    ll hashValue = 0;
    int cnt = 0 , ans = 0;
    for(int i=idx; i<s.size() ; i++)
    {
        if(!check[s[i]])
            cnt++;
        if(cnt>k)
            break;
        hashValue = (hashValue*base) + s[i];
        if(mp[hashValue])
            continue;
        mp[hashValue] = 1;
        ans++;
    }
    return ans;
}
int main()
{
    FastRead

    string s,s1;
    ll x , ans = 0;
    int k = 0;
    cin >> s;
    cin >> s1;

    for(int i=0;i<26;i++)
    {
        if(s1[i] == '1')
            check[Mem[i]] = 1;
        else
            check[Mem[i]] = 0;
    }
    cin >> k;
    for(int i=0;i<s.size();i++)
        ans += getHash(s,k,i);

    cout << ans << endl;
}

/// Solution-2
#include<bits/stdc++.h>
using namespace std;

#define ll           unsigned long long
#define MOD          (ll)1e9+7
#define MAX          (ll)2000
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll save[MAX];
ll prime = 73939133;
map < ll,bool > mp;
map < char,bool > check;
string Mem = "abcdefghijklmnopqrstuvwxyz";

void pre()
{
    save[0] = 1;
    for(ll i=1; i<MAX; i++)
        save[i] = (save[i-1]*prime)%MOD;
}

ll getHash(string s,ll k,ll idx)
{
    ll hashValue = 0;
    int cnt = 0 , ans = 0;
    for(ll i=idx , j = 0; i<s.size(); i++ , j++)
    {
        if(!check[s[i]])
            cnt++;
        if(cnt>k)
            break;
        hashValue += s[i]*save[j];
        if(mp[hashValue])
                continue;
        mp[hashValue] = 1;
        ans++;
    }
    return ans;
}

int main()
{
    FastRead
    pre();
    string s,s1;
    ll ans = 0;
    int k = 0;
    cin >> s;
    cin >> s1;
    for(int i=0;i<26;i++)
    {
        if(s1[i] == '1')
            check[Mem[i]] = 1;
        else
            check[Mem[i]] = 0;
    }
    cin >> k;
    for(int i=0;i<s.size();i++)
        ans += getHash(s,k,i);

    cout << ans << endl;
}


/**
Problem : Common Divisors
Link : http://codeforces.com/contest/182/problem/D
Solution :
**/
#include<bits/stdc++.h>
using namespace std;

#define ll           unsigned long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll getHash(string s)
{
    ll hashValue = 0;

    for(int i=0; i<s.size(); i++)
        hashValue = (hashValue*13331) + s[i];

    return hashValue;
}

bool check(string s,string s1,ll h)
{
    int n = s.size(), k = s1.size();

    if(n%k != 0)
        return false;

    int kk = n/k;
    string ans = "";

    while(kk--)
        ans += s1;

    if(getHash(ans) != h)
        return false;

    return true;
}
int main()
{
    FastRead

    string s1,s2,temp;
    cin >> s1 >> s2;

    if(s1.size() > s2.size())
        swap(s1,s2);

    ll cnt = 0 , sz;
    ll h1 = getHash(s1), h2 = getHash(s2);
    string ss = "";
    int n = s1.size();
    int m = s2.size();
    int lim = sqrt(n);

    for(int i=1; i<=lim; i++)
    {
        if(s1[i-1] != s2[i-1])
            break;
        ss += s1[i-1];
        if(check(s1,ss,h1) && check(s2,ss,h2))
                cnt++;
        sz = n/i;
        if(sz > sqrt(n))
        {
            temp = ss;

            for(int j=i+1; j<=sz; j++)
                temp += s1[j-1];
            if(check(s1,temp,h1) && check(s2,temp,h2))
                cnt++;
        }
    }
    cout << cnt << endl;
}

/**
Problem : Password
Link : http://codeforces.com/contest/126/problem/B
Solution :
**/
#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e9+7
#define MAX          (int)1e6+5
#define ll           unsigned long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

int base = 13331;
ll H[MAX],save[MAX];
void pre()
{
    save[0] = 1;
    for(int i=1;i<MAX;i++)
        save[i] = save[i-1]*base;
}
void setHash(string s)
{
    H[0] = 1;
    for(int i=1;i<s.size();i++)
        H[i] = H[i-1]*base + s[i];
}
ll getHash(int l,int r)
{
    return H[r]-save[r-l+1]*H[l-1];
}
int main()
{
    FastRead

    string s;
    cin >> s;
    pre();
    s = "#"+s;
    setHash(s);
    int len = s.size();
    for(int i=len-2;i>0;i--)
    {
        ll h1 = getHash(1,i);
        ll h2 = getHash(len-i,len-1);
        if(h1 == h2)
        {
            int idx = i;
            for(int j=2;j+idx<len;j++)
            {
                if(getHash(j,j+idx-1) == h1)
                {
                    cout << s.substr(j,idx) << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Just a legend\n";
}

/**
Problem : Making Huge Palindromes
Link : http://lightoj.com/volume_showproblem.php?problem=1258
Solution :
**/
#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e9+7
#define MAX          (int)1e6+5
#define ll           unsigned long long
#define pii          pair<ll,ll>
#define sf(a)        scanf("%d",&a)
#define pf(a)        printf("%d\n",a)
#define bug(a)       cerr << #a << " : " << a << endl;
#define mem(a,b)     memset(a,b,sizeof(a))
#define all(x)       x.begin(),x.end()
#define rall(x)      x.rbegin(),x.rend()
#define pb           push_back
#define F            first
#define S            second
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll pw[MAX] , H1[MAX] , H2[MAX];
int base = 1331;
void setPow()
{
    pw[0] = 1;
    for(int i=1;i<MAX;i++)
        pw[i] = pw[i-1]*base;
}
ll setHash(string s)
{
    H1[0] = 0;
    for(int i=1;i<s.size();i++)
        H1[i] = H1[i-1]*base+s[i];

    H2[s.size()] = 0;
    for(int i=s.size()-1;i>=0;i--)
        H2[i] = H2[i+1]*base+s[i];

}
ll getHash1(int l,int r)
{
    return H1[r]-(H1[l-1]*pw[r-l+1]);
}
int main()
{
    int t,cas=1;
    cin >> t;
    setPow();
    while(t--)
    {
        string s;
        cin >> s;
        s = "#"+s;
        int n = s.size();
        int mn = 1e9;
        setHash(s);
        for(int i=1;i<n;i++)
        {
            int x = n-i;
            if(i>=x)
            {
                if(H2[i] == getHash1(i-x+1,i))
                    mn = min(mn,n-1+(i-x));
            }
            if(i>x)
            {
                if(H2[i] == getHash1(i-x,i-1))
                    mn = min(mn,n-1+(i-x-1));
            }
        }
        cout << "Case " << cas++ << ": " << mn << endl;
    }
}

/**
Problem Name : Substring Frequency
Problem Link : http://lightoj.com/volume_showproblem.php?problem=1255
Solution :
**/
#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e9+7
#define MAX          (int)1e6+5
#define ll           long long
#define pii          pair<ll,ll>
#define sf(a)        scanf("%d",&a)
#define pf(a)        printf("%d\n",a)
#define bug(a)       cerr << #a << " : " << a << endl;
#define mem(a,b)     memset(a,b,sizeof(a))
#define all(x)       x.begin(),x.end()
#define rall(x)      x.rbegin(),x.rend()
#define pb           push_back
#define F            first
#define S            second
#define Time()       cout<< "\nElapsed Time : " << (clock()*1.0) / CLOCKS_PER_SEC <<" sec"<< endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll base = 1331;
ll pw[MAX];
void preCalc()
{
    pw[0] = 1;
    for(int i=1;i<MAX;i++)
        pw[i] = pw[i-1]*base;
}
ll H[MAX];
void setHash(string s)
{
    H[0] = 0;
    for(int i=1;i<s.size();i++)
        H[i] = H[i-1]*base+s[i];
}
ll getHash(int l,int r)
{
    return H[r]-(H[l-1]*pw[r-l+1]);
}
ll Hasher(string s)
{
    ll hashValue = 0;
    for(int i=0;i<s.size();i++)
        hashValue = hashValue*base+s[i];
    return hashValue;
}
int main()
{
    FastRead
    preCalc();
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a >> b;

        a = "#"+a;
        setHash(a);
        int l1 = a.size() , l2 = b.size();

        ll hashValue = Hasher(b);
        int cnt = 0;
        for(int i=1;i+l2<=l1;i++)
        {
            int l = i , r = i+l2-1;
            if(getHash(l,r) == hashValue)
                cnt++;
        }
        cout << "Case " << cas++ << ": " << cnt << endl;
    }
}

/**
Problem Name : Death Stars (medium)
Problem Link : https://codeforces.com/contest/958/problem/A2
Solution :
**/
#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e15+7
#define ll           unsigned long long
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

ll pw[2005], base = 13331 , base2 = 237;
void preCalc()
{
    pw[0] = 1;
    for(int i=1; i<2005; i++)
        pw[i] = (pw[i-1]*base);
}

string s2[205];
ll H[205][2005], H1[2005] , savedH[2005][2005];
void setHash(int m)
{
    for(int i=0; i<m; i++)
    {
        H[i][0] = 0;
        s2[i] = "#"+s2[i];
        for(int j=1; j<s2[i].size(); j++)
            H[i][j] = H[i][j-1]*base+s2[i][j];
    }
}
ll getHash(int m,int l,int r)
{
    ll hashValue = 0;
    for(int i=0; i<m; i++)
        hashValue = hashValue*base2 + (H[i][r]-(H[i][l-1]*pw[r-l+1]));
    return hashValue;
}

ll Hasher(string s)
{
    ll hashValue = 0;
    for(int i=0; i<s.size(); i++)
        hashValue = hashValue*base+s[i];
    return hashValue;
}

int main()
{
    FastRead
    preCalc();
    int n,m;
    cin >> n >> m;
    string s1;
    for(int i=0; i<n; i++)
    {
        cin >> s1;
        H1[i] = Hasher(s1);
    }
    for(int j=0; j<m; j++)
        cin >> s2[j];
    setHash(m);

    /// PreCalculations
    for(int j=1; j+m-1<=n; j++)
    {
        int l = j , r = j+m-1;
        savedH[l][r] = getHash(m,l,r);
    }

    for(int i=0; i+m<=n; i++)
    {
        ll hashValue = 0;
        for(int j=i; j<i+m; j++)
            hashValue = hashValue*base2 + H1[j];
        for(int j=1; j+m-1<=n; j++)
        {
            int l = j , r = j+m-1;
            if(savedH[l][r] == hashValue)
            {
                cout << i+1 << " " << j << endl;
                return 0;
            }
        }
    }
}
