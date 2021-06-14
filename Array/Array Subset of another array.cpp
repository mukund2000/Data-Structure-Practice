#include <iostream>
#include<bits/stdc++.h>
using namespace std;
bool isSubset(int a[],int b[],int n,int m)
{
    set<int> hash;
    for(int i=0;i<n;i++)
    hash.insert(a[i]);
    for(int i=0;i<m;i++)
    {
        if(hash.find(b[i])==hash.end())
        return false;
    }
    return true;
}
bool isSubsetFre(int a[],int b[],int n,int m)
{
    map<int,int> table;
    for(int i=0;i<n;i++)
        table[a[i]]++;
    for(int i=0;i<m;i++)
    {
        if(table[b[i]]>0)
            table[b[i]]--;
        else
            return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<m;i++)
        cin>>b[i];
        bool f=isSubsetFre(a,b,n,m);
        if(f)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
	//code
	return 0;
}
