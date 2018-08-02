/**
Discovering Permutations Solution [ LightOJ ]
Problem Link : http://lightoj.com/volume_showproblem.php?problem=1023
Solution :
**/

#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int n,k;
char ch[27];
bool used[27];
void permutation(int pos)
{
    if(k == 0)
        return;
    else if(pos == n)
    {
        k--;
        for(int i=0; i<n; i++)
            cout << ch[i];
        cout << endl;
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(used[i])
            continue;
        used[i] = 1;
        ch[pos] = i+'A';
        permutation(pos+1);
        used[i] = 0;
    }
}
int main()
{
    FastRead
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        memset(used,0,sizeof used);
        cin >> n >> k;
        cout << "Case " << cas++ << ":\n";
        permutation(0);
    }
}

/// Solution with STL :
#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int n,k;
int main()
{
    FastRead
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << "Case " << cas++ << ":\n";
        string characters = "";
        for(int i=0;i<n;i++)
            characters += ('A'+i);
        do
        {
            for(int i=0;i<n;i++)
                cout << characters[i];
            cout << endl;
            k--;
        }
        while(next_permutation(characters.begin(),characters.end()) && k);
    }
}
