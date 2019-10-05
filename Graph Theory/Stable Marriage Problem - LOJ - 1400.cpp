#include<bits/stdc++.h>
using namespace std;

#define ll           long long
#define pii          pair<ll,ll>
#define bug(a)       cerr << #a << " : " << a << endl;
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAX = 105;

int men[MAX][MAX], women[MAX][MAX], choices;
int freeMen[MAX], freeWomen[MAX] , pos[MAX][MAX];

int n;

int isFree()
{
    for(int i=1; i<=n; i++)
    {
        if(freeMen[i])
            continue;
        for(int j=0; j<choices; j++)
        {
            if(!freeWomen[men[i][j]])
                return i;
        }
    }
    return -1;
}

void stableMarriageProblem()
{
    memset(freeMen,0,sizeof freeMen);
    memset(freeWomen,0,sizeof freeWomen);

    while(1)
    {
        int cur = isFree();
        if(cur == -1)
            break;

        for(int j=0; j<choices; j++)
        {
            if(!freeWomen[men[cur][j]])
            {
                freeMen[cur] = men[cur][j];
                freeWomen[men[cur][j]] = cur;
                break;
            }
            else
            {
                int curW = men[cur][j];

                if(pos[curW][freeWomen[curW]] > pos[curW][cur])
                {
                    freeMen[freeWomen[curW]] = 0;
                    freeMen[cur] = curW;
                    freeWomen[curW] = cur;
                    break;
                }
            }
        }
    }
}

int main()
{
    int t,cas=1;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        choices = n;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<choices; j++)
            {
                scanf("%d",&men[i][j]);
                men[i][j] -= n;
            }
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<choices; j++)
            {
                scanf("%d",&women[i][j]);
                pos[i][women[i][j]] = j;
            }
        }

        stableMarriageProblem();

        printf("Case %d:",cas++);
        for(int i=1;i<=n;i++)
        {
            if(freeMen[i])
                printf(" (%d %d)",i,freeMen[i]+n);
        }
        printf("\n");
    }
}
