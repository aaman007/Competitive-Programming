#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct trieNode
{
    trieNode *child[10];
    bool is_end;
    trieNode()
    {
        for(int i=0; i<10; i++)
            child[i] = NULL;
        is_end = false;
    }
};
trieNode *root;
bool ans;
void Insert(string s)
{
    trieNode *cur = root;
    for(int i=0; i<s.size(); i++)
    {
        int idx = s[i]-'0';
        if(cur->child[idx] == NULL)
            cur->child[idx] = new trieNode();
        cur = cur->child[idx];
        if(cur->is_end == true)
            ans = true;
    }
    for(int i=0; i<10; i++)
        if(cur->child[i])
        {
            ans = true;
            break;
        }
    cur->is_end = true;
}
void del(trieNode *cur)
{
    for(int i=0; i<10; i++)
        if(cur->child[i])
            del(cur->child[i]);
    delete(cur);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        root = new trieNode();
        int n;
        string s;
        cin >> n;
        ans = false;
        while(n--)
        {
            cin >> s;
            if(!ans)
                Insert(s);
        }
        cout << "Case " << cas++ << ": ";
        if(ans)
            cout << "NO\n";
        else
            cout << "YES\n";
        del(root);
    }
}
