/// Linear Search is the easiest search algo.Code in C/C++ is given :
#include<stdio.h>
int main()
{
    int ara[100],n,i,key,cas=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0; i<n; i++)
            scanf("%d",&ara[i]);
        scanf("%d",&key);
        for(i=0; i<n; i++)
        {
            if(ara[i]==key)
                break;
        }
        printf("case %d: ",cas);
        cas++;
        if(i==n)
            printf("No\n");
        else
            printf("%d\n\n",i+1);
    }
    return 0;
}

/// C++ COde
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[100],n,i,key,cas=1;
    while(cin >> n)
    {
        for(i=0; i<n; i++)
            scanf("%d",&ara[i]);

        cin >> key;

        for(i=0; i<n; i++)
        {
            if(ara[i]==key)
                break;
        }
        printf("Case %d: ",cas);
        cas++;
        if(i==n)
            cout << "Not Found!!\n";
        else
            cout << "Found at : " << i+1 << endl;;
    }
    return 0;
}
