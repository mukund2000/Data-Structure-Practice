#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> S;
    int ans=0;
    for(int i=0;i<N;i++)
    S.insert(arr[i]);

    for(int i=0;i<N;i++)
    {
        if(S.find(arr[i]-1)==S.end())
        {
            int j=arr[i];
            while(S.find(j)!=S.end())
            j++;
            ans=max(ans,j-arr[i]);
        }
    }
    return ans;
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
     cout<<findLongestConseqSubseq(a,n);
 }

