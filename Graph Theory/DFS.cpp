#include<bits/stdc++.h>
using namespace std;
vector < int > A[100];
int v,e;
bool visited[100];
stack < int > B;
void Input()
{
    int a,b;
    cout << "Enter number of vertices and edges\n";
    cin >> v >> e;
    cout << "Enter the Graph's connections\n";
    for(int i=1;i<=e;i++)
    {
        cin >> a >> b;
        A[a].push_back(b);
        A[b].push_back(a);
    }
}
void dfs(int start)
{
    visited[start] = true;
    B.push(start);
    while(!B.empty())
    {
        int n = B.top();
        B.pop();
        cout << n << endl;
        for(int i=0;i<A[n].size();i++)
        {
            int x = A[n][i];
            if(!visited[x])
            {
                B.push(x);
                visited[x] = true;
            }
        }
    }
}
int main()
{
    Input();
    int start;
    cout << "Enter the value of starting point : ";
    cin >> start;
    cout << endl;
    dfs(start);
}
