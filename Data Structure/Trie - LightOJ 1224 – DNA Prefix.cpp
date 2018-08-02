#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
struct trie
{
    trie *child[4];
    int cnt;
    trie()
    {
        for(int i=0;i<4;i++)
            child[i] = NULL;
        cnt = 0;
    }
};
trie *root;
int Index(char ch)
{
    if(ch == 'A')
        return 0;
    else if(ch == 'C')
        return 1;
    else if(ch == 'G')
        return 2;
    return 3;
}
void Insert(std::string s)
{
    trie *cur = root;
    for(int i=0;i<s.size();i++)
    {
        int idx = Index(s[i]);
        if(!cur->child[idx])
            cur->child[idx] = new trie();
        cur = cur->child[idx];
        cur->cnt++;
    }
}
ll mx;
void dfs(trie *cur,int level)
{
    ll temp = (cur->cnt)*level;
    if(temp>mx)
        mx = temp;
    for(int i=0;i<4;i++)
    {
        if(cur->child[i])
            dfs(cur->child[i],level+1);
    }
}
void del(trie *cur)
{
    for(int i=0;i<4;i++)
        if(cur->child[i])
            del(cur->child[i]);
    delete(cur);
}
using namespace std;
int main()
{
    FastRead
    int t , cas = 1;
    cin >> t;
    while(t--)
    {
        root = new trie();
        int n;
        string s;
        cin >> n;
        mx = 0;
        while(n--)
        {
            cin >> s;
            Insert(s);
        }
        dfs(root,0);
        cout << "Case " << cas++ << ": " << mx << endl;
        del(root);
    }
}
