#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxProduct(int arr[], int n) {
	    int curr_max_prod=arr[0];
	    int curr_min_prod=arr[0];
	    int prev_min_prod=arr[0];
	    int prev_max_prod=arr[0];
	    int ans=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        curr_max_prod=max(arr[i],max(prev_max_prod*arr[i],prev_min_prod*arr[i]));
	        curr_min_prod=min(arr[i],min(prev_max_prod*arr[i],prev_min_prod*arr[i]));
	        ans=max(ans,curr_max_prod);
	        prev_max_prod=curr_max_prod;
	        prev_min_prod=curr_min_prod;
	    }
	    return ans;
	    // code here
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
     cout<<maxProduct(a,n);
 }
