#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Pair
{
    int mx;
    int mn;
};
struct Pair MinMax(int arr[],int n)
{
    struct Pair mnmx;
    int i;
    if(n==1)
    {
        mnmx.mn=arr[0];
        mnmx.mx=arr[0];
        return mnmx;
    }
    if(arr[0]>arr[1])
    {
        mnmx.mn=arr[1];
        mnmx.mx=arr[0];
    }
    else
    {
        mnmx.mx=arr[1];
        mnmx.mn=arr[0];
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]>mnmx.mx)
        {
            mnmx.mx=arr[i];
        }
        else if(mnmx.mn>arr[i])
            mnmx.mn=arr[i];
    }
    return mnmx;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    struct Pair out = MinMax(a,n);
    cout<<out.mx<<" "<<out.mn<<"\n";
    return 0;
}
