#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

vector<int> createLPSArray(string pattern)
{
    vector<int> lps(pattern.size());

    int index = 0;
    for(int i=1;i<pattern.size();)
    {
        if(pattern[index] == pattern[i])
        {
            lps[i] = index+1;
            index++ , i++;
        }
        else
        {
            if(index)
                index = lps[index-1];
            else
                lps[i] = index , i++;
        }
    }

    return lps;
}
bool KMP(string text,string pattern)
{
    vector<int> lps = createLPSArray(pattern);

    int i = 0 , j = 0;

    while(i < text.size())
    {
        if(text[i] == pattern[j])
            i++ , j++;
        else
        {
            if(j)
                j = lps[j-1];
            else
                i++;
        }

        if(j == pattern.size())
            return true;
    }

    return false;
}
int countKMP(string text,string pattern)
{
    vector<int> lps = createLPSArray(pattern);

    int i = 0 , j = 0 , cnt = 0;

    while(i < text.size())
    {
        if(text[i] == pattern[j])
            i++ , j++;
        else
        {
            if(j)
                j = lps[j-1];
            else
                i++;
        }

        if(j == pattern.size())
        {
            cnt++;
            j = lps[j-1];
        }
    }

    return cnt;
}
int main()
{
    FastRead

    string text , pattern;

    cin >> text;

    while(cin >> pattern)
    {
        if(KMP(text,pattern))
        {
            cout << "Found!!\n";
            cout << pattern << " appears " << countKMP(text,pattern) << " times\n";
        }
        else
            cout << "Not Found!!\n";
    }
}
