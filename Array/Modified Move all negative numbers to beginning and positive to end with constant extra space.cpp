#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void rearrange(int a[],int l,int r)
{
    while(l<=r)
    {
        if(a[l]<0 && a[r]<0)
            l++;
        else if(a[l]>0 && a[r]<0)
        {
            swap(a[l],a[r]);
            l++;
            r--;
        }
        else if(a[l]>0 && a[r]>0)
            r--;
        else
        {
            l++;
            r--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    rearrange(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

