#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void nextpermutation(int a[],int n)
{
    int k,l;
    for(k=n-2;k>=0;k--)
    {
        if(a[k]<a[k+1])
        break;
    }
    if(k<0)
    {
        reverse(a,a+n);
    }
    else
    {
        for(l=n-1;l>=0;l--)
        {
            if(a[l]>a[k])
            break;
        }
        swap(a[k],a[l]);
        reverse(a+k-1,a+n);
    }

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    nextpermutation(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
