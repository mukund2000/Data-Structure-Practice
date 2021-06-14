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
    if(n%2)
    {
        mnmx.mn=arr[0];
        mnmx.mx=arr[0];
        i=1;
    }
    else
    {
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
    i=2;
    }
    while(i<n-1)
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>mnmx.mx)
                mnmx.mx=arr[i];
            else if(arr[i+1]<mnmx.mn)
                mnmx.mn=arr[i+1];
        }
        else
        {
            if(arr[i]<mnmx.mn)
                mnmx.mn=arr[i];
            else if(arr[i+1]>mnmx.mx)
                mnmx.mx=arr[i+1];
        }
        i+=2;
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
