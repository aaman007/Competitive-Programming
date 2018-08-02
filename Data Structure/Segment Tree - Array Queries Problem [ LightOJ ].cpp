#include<bits/stdc++.h>
#define sf(a) scanf("%d",&a)
#define pf(a) printf("%d\n",a)
using namespace std;
const int MX = 1e5+2;
int a[MX] , tree[4*MX];
int build(int att,int L,int R)
{
    if(L == R)
        return tree[att] = a[L];
    int mid = (L+R)/2;
    int x = build(att*2,L,mid);
    int y = build(att*2+1,mid+1,R);
    return tree[att] = min(x,y);
}
int query(int att,int L,int R,int l,int r)
{
    if(r<L || l>R)
        return INT_MAX;
    else if(l<=L && r>=R)
        return tree[att];
    int mid = (L+R)/2 , x , y;
    x = query(att*2,L,mid,l,r);
    y = query(att*2+1,mid+1,R,l,r);
    return min(x,y);
}
int main()
{
    int t,cs=1,n,q,x,y;
    sf(t);
    while(t--)
    {
        sf(n);
        sf(q);
        for(int i=1;i<=n;i++)
            sf(a[i]);
        build(1,1,n);
        printf("Case %d:\n",cs++);
        while(q--)
        {
            sf(x) , sf(y);
            printf("%d\n",query(1,1,n,x,y));
        }
    }
}
