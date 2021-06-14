#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int First(vector<int> &arr,int low,int high)
{
    if(high>=low)
    {
        int mid=(low+high)/2;
        if((mid==0|| arr[mid-1])&&arr[mid]==1)
        return mid;
        else if(arr[mid]==0)
        return First(arr,(mid+1),high);
        else
        return First(arr,low,(mid-1));
    }
    return -1;
}
	int rowWithMax1s(vector<vector<int>> arr, int n, int m) {
	    int max_index=0,index;
	    int max=First(arr[0],0,m-1);
	    for(int i=1;i<n;i++)
	    {
	        if(max!=-1&&arr[i][m-max-1]==1)
	        {
	            index=First(arr[i],0,m-max);
	            if(index!=-1 && m-index>max)
	            {
	                max=m-index;
	                max_index=i;
	            }
	        }
	        else
	        {
	            max=First(arr[i],0,m-1);
	        }
	    }
	    return max_index;
	    // code here
	}
int main()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> a(r);
    for(int i=0;i<r;i++)
    {
        a[i].assign(c,0);
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int res=rowWithMax1s(a,r,c);
    cout<<res<<"\n";
}
