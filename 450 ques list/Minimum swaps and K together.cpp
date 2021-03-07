#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int MinSwaps(int a[],int n,int k)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=k)
        ++cnt;
    }
    int bad=0;
    for(int i=0;i<cnt;i++)
    {
        if(a[i]>k)
        ++bad;
    }
    int ans=bad;
    for(int i=0,j=cnt;j<n;j++,i++)
    {
        if(a[i]>k)
        --bad;
        if(a[j]>k)
        ++bad;
        ans=min(ans,bad);
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int k;
        cin>>k;
        cout<<MinSwaps(a,n,k)<<"\n";
    }
	//code
	return 0;
}
