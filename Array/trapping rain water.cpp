#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int FindWater(int arr[],int n)
{
    int left[n],right[n],water=0;
    left[0]=arr[0];
    for(int i=1;i<n;i++)
        left[i]=max(left[i-1],arr[i]);
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],arr[i]);
    }
    for(int i=0;i<n;i++)
        water+=min(left[i],right[i])-arr[i];
    return water;
}
int Trap(int a[],int n)
{
    int lm=0,rm=0;
    int res=0,lo=0,hi=n-1;
    while(lo<=hi)
    {
        if(a[lo]<a[hi])
        {
            if(a[lo]>lm)
            lm=a[lo];
            else
            res+=lm-a[lo];
            lo++;
        }
        else
        {
            if(a[hi]>rm)
            {
                rm=a[hi];
            }
            else
            res+=rm-a[hi];
            hi--;
        }
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<FindWater(a,n)<<"\n";
    }
	//code

	return 0;
}
