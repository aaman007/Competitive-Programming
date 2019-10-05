#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 1e6;

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
Matrix multiply(Matrix a,Matrix b,int MOD)
{
    Matrix c = Matrix(a.n,b.m);

    for(int i=0; i<a.n; i++)
    {
        for(int j=0; j<b.m; j++)
        {
            c.mat[i][j] = 0;
            for(int k=0; k<a.m; k++)
            {
                c.mat[i][j] += (1LL * a.mat[i][k] * b.mat[k][j])%MOD;
                if(c.mat[i][j] >= MOD)
                    c.mat[i][j] -= MOD;
            }
        }
    }
    return c;
}
Matrix pow(Matrix a,ll p,int MOD)
{
    if(p == 1)
        return a;

    Matrix x = pow(a,p/2,MOD);
    x = multiply(x,x,MOD);

    if(p&1)
        x = multiply(x,a,MOD);
    return x;
}
Matrix createA(int a1,int a2,int b1,int b2,int c1,int c2)
{
    Matrix a(6,6);

    a.mat[0][0] = a1, a.mat[0][1] = b1, a.mat[0][5] = c1;
    a.mat[3][3] = a2, a.mat[3][4] = b2, a.mat[3][2] = c2;
    a.mat[1][0] = a.mat[2][1] = a.mat[4][3] = a.mat[5][4] = 1;

    return a;
}
Matrix createB(int f[],int g[])
{
    Matrix a(6,1);

    a.mat[0][0] = f[2];
    a.mat[1][0] = f[1];
    a.mat[2][0] = f[0];
    a.mat[3][0] = g[2];
    a.mat[4][0] = g[1];
    a.mat[5][0] = g[0];

    return a;
}
void print(Matrix A)
{
    for(int i=0; i<A.n; i++)
        for(int j=0; j<A.m; j++)
            cout << A.mat[i][j] << " \n"[j ==A.m-1];
}
int main()
{
    FastRead

    int t,cas=1;

    cin >> t;

    while(t--)
    {
        int a1,b1,c1,a2,b2,c2,n,q;

        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

        int f[3], g[3];

        for(int i=0; i<3; i++)
            cin >> f[i];
        for(int i=0; i<3; i++)
            cin >> g[i];

        int MOD,ans1,ans2;

        cin >> MOD;

        Matrix A = createB(f,g);

        cin >> q;

        cout << "Case " << cas++ << ":\n";
        while(q--)
        {
            cin >> n;

            if(n <= 2)
            {
                ans1 = f[n]%MOD;
                ans2 = g[n]%MOD;
            }
            else
            {
                Matrix M = pow(createA(a1,a2,b1,b2,c1,c2),n-2,MOD);

                ans1 = multiply(M,createB(f,g),MOD).mat[0][0];
                ans2 = multiply(M,createB(f,g),MOD).mat[3][0];
            }

            cout << ans1 << " " << ans2 << endl;
        }
    }
}
