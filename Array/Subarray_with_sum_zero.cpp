#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumSet;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0|| sumSet.find(sum)!=sumSet.end())
        return true;
        sumSet.insert(sum);
    }
    return false;
    //Your code here
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
     bool f=subArrayExists(a,n);
     if(f)
     cout<<"SubArray with sum 0 is possible!";
     else
        cout<<"Not Possible.";
 }
