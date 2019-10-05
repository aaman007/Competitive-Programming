#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<int,int>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 3e4+10;

vector<int>adj[MAX];
int a[MAX];

///  For HLD Function
int chainNo, ptr, chainHead[MAX], chainPos[MAX], chainIdx[MAX] , sub[MAX] , maxSub[MAX];

/// For Segment Tree and BIT
int arr[MAX], tree[4*MAX];

/// For LCA
int dep[MAX], T[MAX], P[MAX][20];

void init(const int& n)
{
    for(int i=1; i<=n; i++)
        adj[i].clear();
    chainNo = 0;
    ptr = 0;
    memset(chainHead,-1,sizeof chainHead);
    memset(tree,0,sizeof tree);
}

/// BIT Part
void BIT_Update(int idx,const int& x,const int& n)
{
    while(idx <= n)
    {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}
int BIT_Query(int idx,const int& n)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
int BIT_Query(int l,int r,const int& n)
{
    return BIT_Query(r,n)-BIT_Query(l-1,n);
}

/// Segment Tree Part
void segBuild(int pos,int l,int r)
{
    if(l == r)
    {
        tree[pos] = arr[l];
        return;
    }

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    segBuild(lt,l,mid);
    segBuild(rt,mid+1,r);

    tree[pos] = tree[lt]+tree[rt];
}
void segUpdate(int pos,int l,int r,int idx,int val)
{
    if(l == r)
    {
        tree[pos] = val;
        return;
    }

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    if(idx <= mid)
        segUpdate(lt,l,mid,idx,val);
    else
        segUpdate(rt,mid+1,r,idx,val);

    tree[pos] = tree[lt]+tree[rt];
}
int segQuery(int pos,int l,int r,int L,int R)
{
    if(l > R || r < L)
        return 0;
    else if(l >= L && r <= R)
        return tree[pos];

    int mid = (l+r)/2, lt = pos*2, rt = pos*2+1;

    int x = segQuery(lt,l,mid,L,R);
    int y = segQuery(rt,mid+1,r,L,R);

    return x+y;
}

/// LCA Part
void DFS(int src,int par,int lev)
{
    dep[src] = lev;
    T[src] = par;
    sub[src] = 1 , maxSub[src] = -1;
    int mx = 0;

    for(int i=0; i<adj[src].size(); i++)
    {
        int x = adj[src][i];

        if(x == par)
            continue;

        DFS(x,src,lev+1);
        sub[src] += sub[x];

        if(sub[x] > mx)
            mx = sub[x] , maxSub[src] = x;
    }
}
void initLCA(const int& n)
{
    memset(P,-1,sizeof P);

    for(int i=1; i<=n; i++)
        P[i][0] = T[i];

    for(int j=1; 1<<j <n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(P[i][j-1] != -1)
                P[i][j] = P[P[i][j-1]][j-1];
        }
    }
}
int LCA_query(const int& n,int u,int v)
{
    if(dep[u] < dep[v])
        swap(u,v);

    int log = log2(dep[u]);

    for(int i=log; i>=0; i--)
    {
        if(dep[u]-(1<<i) >= dep[v])
            u = P[u][i];
    }

    if(u == v)
        return u;

    for(int i=log; i>=0; i--)
    {
        if(P[u][i] != -1 && P[u][i] != P[v][i])
        {
            u = P[u][i];
            v = P[v][i];
        }
    }
    return T[u];
}

/// HLD Part
void HLD(int cur,int par)
{
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = cur;

    chainIdx[cur] = chainNo;
    chainPos[cur] = ++ptr;
    arr[ptr] = a[cur];

    if(maxSub[cur] != -1)
        HLD(maxSub[cur],cur);

    for(int j=0; j<adj[cur].size(); j++)
    {
        int i = adj[cur][j];

        if(i != par && i != maxSub[cur])
            chainNo++, HLD(i,cur);
    }
}
int query_up(int u,int v,const int& n)
{
    int uchain , vchain = chainIdx[v] , ans = 0;

    while(chainIdx[u] != vchain)
    {
        uchain = chainIdx[u];

        ans += BIT_Query(chainPos[chainHead[uchain]],chainPos[u],n);

        u = chainHead[uchain];
        u = P[u][0];
    }
    ans += BIT_Query(chainPos[v],chainPos[u],n);

    return ans;
}
void ansUpdate(int i,int v,const int& n)
{
    BIT_Update(chainPos[i],-a[i],n);
    BIT_Update(chainPos[i],v,n);
    a[i] = v;
}
int ansQuery(const int& n,int u,int v)
{
    int lca = LCA_query(n,u,v);

    int q1 = query_up(u,lca,n);
    int q2 = query_up(v,lca,n);

    return q1+q2-a[lca];
}
int main()
{
    int t,cas=1;
    int n,q,u,v,type;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        init(n+5);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            u++,v++;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(1,-1,0);
        initLCA(n);
        HLD(1,-1);

        for(int i=1;i<=ptr;i++)
            BIT_Update(i,arr[i],n);;

        scanf("%d",&q);
        printf("Case %d:\n",cas++);

        while(q--)
        {
            scanf("%d%d%d",&type,&u,&v);

            if(type == 1)
                ansUpdate(u+1,v,n);
            else
                printf("%d\n",ansQuery(n,u+1,v+1));
        }
    }
}
