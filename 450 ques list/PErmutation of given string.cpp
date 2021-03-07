#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void solve(string s,int l,int r,vector<string>& str)
{
    if(l==r)
    {
        str.push_back(s);
        return;
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(s[l],s[i]);
            solve(s,l+1,r,str);
            swap(s[l],s[i]);
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.size();
        vector<string> str;
        solve(s,0,n-1,str);
        sort(str.begin(),str.end());
        for(int i=0;i<str.size();i++)
        {
            cout<<str[i]<<" ";
        }
        cout<<"\n";
    }

	//code
	return 0;
}
