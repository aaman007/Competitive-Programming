/// Binary Search Code in C :
#include<stdio.h>
int main()
{
    int a[13] = {12,23,30,32,38,42,50,60,65,70,85,90,100};
    int start=0,end=12,mid,key;
    scanf("%d",&key);
    do
    {
        mid = (int)((start+end)/2);
        printf("Start:%d\tEnd:%d\tmid:%d\tKey:%d\ta[mid]:%d\n",start,end,mid,key,a[mid]);

        if(a[mid] == key )
        {
            printf("Found at number %d",mid+1);
            break;
        }
        else if(a[mid] > key)
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    while( start <= end);
    if(start > end)
    {
        printf("\nNumber couldn't be found\n\n");
        printf("Start:%d\tEnd:%d\tmid:%d\tKey:%d\ta[mid]:%d\n",start,end,mid,key,a[mid]);

    }
    return 0;
}

/// Binary Search Code in C++ using Recursion & Pointer :
#include<bits/stdc++.h>
using namespace std;
int *a;
int binary_search(int start,int endd,int key)
{
    int mid = (start+endd)/2;
    if(a[mid]==key)
        return mid+1;
    else
    {
        if(start>=endd)
            return 0;
        else if(key<a[mid])
            binary_search(start,mid-1,key);
        else if(key>a[mid])
            binary_search(mid+1,endd,key);
    }
}
int main()
{
    cout << "How many elements is in the Array?????????\n";
    int n;
    cin >> n;

    a = new int[n];
    cout << "Enter the elements"<< endl;
    for(int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    cout << "\nElements in ascending order\n";
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;

    int k;
    cout << "\nWhich number you wanna search?????????\n";
    cin >> k;

    int res = binary_search(0,n-1,k);

    if(res)
        cout << "\nFound at Position " << res << endl;
    else
        cout << "\nValue not found!!!!!!!!" << endl;

     delete[] a;
}
