#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Two pointer Approach
bool findSum(int arr[],int n,int sum)
{
    int l,r;
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            if(arr[i]+arr[l]+arr[r]==sum)
                return true;
            else if(arr[i]+arr[l]+arr[r]<sum)
                l++;
            else
                r--;
        }
    }
    return false;
}
// Hashing
bool FindSum(int arr[],int n,int sum)
{
    for(int i=0;i<n-2;i++)
    {
        unordered_set<int> mp;
        int cur_sum=sum-arr[i];
        for(int j=i+1;j<n;j++)
        {
            if(mp.find(cur_sum-arr[j])!=mp.end())
                return true;
            mp.insert(arr[j]);
        }
    }
    return false;
}
int main()
{

    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<FindSum(a,n,sum);
}
