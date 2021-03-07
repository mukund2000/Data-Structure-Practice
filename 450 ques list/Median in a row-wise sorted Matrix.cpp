#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &a, int r, int c){
        int max=INT_MIN,min=INT_MAX;
        for(int i=0;i<r;i++)
        {
            if(min>a[i][0])
            min=a[i][0];
            if(max<a[i][c-1])
            max=a[i][c-1];
        }
        int desired=(r*c+1)/2;
        while(min<max)
        {
            int mid=(max+min)/2;
            int count=0;
            for(int i=0;i<r;i++)
            count+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
            if(count<desired)
            min=mid+1;
            else
            max=mid;
        }
        return min;
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
    int res=median(a,r,c);
    cout<<res<<"\n";
}
