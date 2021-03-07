#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int MinDiff(int arr[],int n,int m)
{
    if(m==0||n==0)
    return 0;
    if(n<m)
    return -1;
    sort(arr,arr+n);
    int min_diff=INT_MAX;
    for(int i=0;i+m-1<n;i++)
    {
        int diff = arr[i+m-1]-arr[i];
        if(diff<min_diff)
        min_diff=diff;

    }
    return min_diff;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cin>>m;
        cout<<MinDiff(a,n,m)<<"\n";

    }
	//code
	return 0;
}
