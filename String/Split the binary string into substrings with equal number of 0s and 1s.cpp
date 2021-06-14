#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int SplitBin(string bin)
{
    int n=bin.size();
    int c1=0,c0=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(bin[i]=='0')
            c0++;
        else if(bin[i]=='1')
            c1++;
        if(c0==c1)
            cnt++;
    }
    if(c0!=c1)
        return -1;
    return cnt;
}
int main()
{
    string bin;
    cin>>bin;
    cout<<SplitBin(bin)<<"\n";
}
