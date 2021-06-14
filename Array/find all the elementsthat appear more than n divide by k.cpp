#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void morethanNdK(int arr[],int n,int k)
{
    int x=n/k;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[arr[i]]++;
    for(auto i:mp)
    {
        if(i.second>x)
        {
            cout<<i.first<<endl;
        }
    }
}
int main()
{

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    morethanNdK(a,n,k);
}
