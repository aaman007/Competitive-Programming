#include<bits/stdc++.h>
using namespace std;

#define MOD          (int)1e9+7
#define MAX          (int)1e5+5
#define ll           long long
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
struct Trie
{
    Trie *digits[10];
    int cnt,idx;
    Trie()
    {
        for(int i=0;i<=9;i++)
            digits[i] = NULL;
        cnt = 0;
        idx = -1;
    }
};

Trie *root;

void Insert(string s,int ii)
{
    Trie *cur = root;
    bool flag = 0;
    for(int i=0;i<s.size();i++)
    {
        int d = s[i]-'0';
        if(cur->digits[d] == NULL)
            cur->digits[d] = new Trie();
        cur = cur->digits[d];
        if(cur->idx != ii)
            flag = 1 , cur->idx = ii;
        if(flag)
            cur->cnt++;
    }
}
bool Search(string s)
{
    Trie *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int d = s[i]-'0';
        cur = cur->digits[d];
        if(cur->cnt == 1)
            return true;
    }
    return false;
}
int main()
{
    FastRead

    int n;
    cin >> n;
    string s[n+2] , temp , mn;
    root = new Trie();
    for(int i=0;i<n;i++)
    {
        cin >> s[i];
        for(int j=0;j<s[i].size();j++)
        {
            temp = "";
            for(int k=j;k<s[i].size();k++)
            {
                temp += s[i][k];
                Insert(temp,i);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        mn = "9999999999";
        for(int j=0;j<s[i].size();j++)
        {
            temp = "";
            for(int k=j;k<s[i].size();k++)
            {
                temp += s[i][k];
                if(Search(temp) && temp.size() < mn.size())
                    mn = temp;
            }
        }
        cout << mn << endl;
    }
}
