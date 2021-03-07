#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        m[arr[i]]++;
        int twice_count=0;
        for(int i=0;i<n;i++)
        {
            twice_count+=m[k-arr[i]];
            if(k-arr[i]==arr[i])
            twice_count--;
        }
        return twice_count/2;
        // code here
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
    cout<<getPairsCount(a,n,sum);
 }
