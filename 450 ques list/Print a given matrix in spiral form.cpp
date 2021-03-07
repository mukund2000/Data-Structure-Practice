#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int> > a, int m, int n)
    {
        int k=0,l=0;
        vector<int> res;
        while(k<m && l<n)
        {
            for(int i=l;i<n;i++)
            res.push_back(a[k][i]);
            k++;

            for(int i=k;i<m;i++)
            res.push_back(a[i][n-1]);
            n--;

            if(k<m)
            {
                for(int i=n-1;i>=l;i--)
                res.push_back(a[m-1][i]);
                m--;
            }
            if(l<n)
            {
                for(int i=m-1;i>=k;i--)
                res.push_back(a[i][l]);
                l++;
            }
        }
        return res;
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
    vector<int> res=spirallyTraverse(a,r,c);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
}
