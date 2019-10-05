#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;
const int MOD = 10;

struct Matrix
{
    int n,m;
    vector< vector<int> > mat;

    Matrix() {}
    Matrix(int _n,int _m)
    {
        n = _n, m = _m;
        mat = vector< vector<int> > (n,vector<int>(m));
    }
};
void print(Matrix A)
{
    for(int i=0; i<A.n; i++)
        for(int j=0; j<A.m; j++)
            cout << A.mat[i][j] << " \n"[j == A.m-1];
}
Matrix multiply(Matrix a,Matrix b)
{
    Matrix c = Matrix(a.n,b.m);
    int i,j,k;

    for(i=0; i<a.n; i++)
    {
        for(j=0; j<b.m; j++)
        {
            c.mat[i][j] = 0;
            for(k=0; k<a.m; k++)
            {
                c.mat[i][j] += (a.mat[i][k] * 1LL * b.mat[k][j])%MOD;

                if(c.mat[i][j] >= MOD)
                    c.mat[i][j] -= MOD;
            }
        }
    }
    return c;
}
Matrix add(Matrix a,Matrix b)
{
    Matrix c = Matrix(a.n,b.n);
    int i,j;

    for(i=0; i<a.n; i++)
    {
        for(j=0; j<b.n; j++)
            c.mat[i][j] = (a.mat[i][j]+b.mat[i][j])%MOD;
    }
    return c;
}
Matrix pow(Matrix a,int p)
{
    if(p == 1)
        return a;

    Matrix x = pow(a,p/2);
    x = multiply(x,x);

    if(p&1)
        x = multiply(x,a);

    return x;
}
Matrix getMat(Matrix a,int p)
{
    if(p == 1)
        return a;

    Matrix ans = getMat(a,p/2);
    Matrix calc = ans;

    if(p%2 == 0)
        calc = multiply(calc,pow(a,p/2));
    else
    {
        calc = add(calc,pow(a,p/2+1));
        calc = multiply(calc,pow(a,p/2));
    }

    return add(ans,calc);
}
int main()
{
    int n,k,t,cas=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&k);

        Matrix A(n,n);

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&A.mat[i][j]);

        Matrix ans = getMat(A,k);

        printf("Case %d:\n",cas++);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d",ans.mat[i][j]);
            }
            printf("\n");
        }
    }
}
