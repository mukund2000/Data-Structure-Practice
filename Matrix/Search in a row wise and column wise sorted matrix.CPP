#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    int i=0,j=M-1;
	    int mn=mat[0][0],mx=mat[N-1][M-1];
	    if(X<mn || X>mx)
	    return 0;
	    while(i<N && j>=0)
	    {
	        if(mat[i][j]==X)
	        return 1;
	        if(mat[i][j]>X)
	        j--;
	        else
	        i++;

	    }
	    return 0;
	    // your code here
	}
int main()
{
    int r,c,x;
    cin>>r>>c>>x;
    vector<vector<int>> a(r);
    for(int i=0;i<r;i++)
    {
        a[i].assign(c,0);
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int res=matSearch(a,r,c,x);
    cout<<res<<"\n";
}
