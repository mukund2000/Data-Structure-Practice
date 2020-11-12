#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n){
    int msf=INT_MIN,meh=0,strt=0,end=0,s=0;
    for(int i=0;i<n;i++)
    {
        meh+=arr[i];
        if(msf<meh)
        {
            msf=meh;
            strt=s;
            end=i;
        }
        if(meh<0)
        {
            s=i+1;
            meh=0;
        }
    }
    return msf;

    // Your code here

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res=maxSubarraySum(a,n);
    cout<<res<<"\n";

}
