#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void duplicates(string s)
{
    int n=s.size();
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++)
        mp[s[i]]++;
    for(auto x:mp)
    {
        if(x.second>1)
            cout<<x.first<<" "<<x.second<<"\n";
    }
}
int main()
{
    string s;
    cin>>s;
    duplicates(s);
}
