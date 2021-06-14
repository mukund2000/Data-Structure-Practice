#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool CheckSuffle(string f,string s,string res)
{
    if(f.length()+s.length()!=res.length())
        return false;
    int i=0,j=0,k=0;
    while(k<res.length())
    {
        if(i<f.length() && f[i]==res[k])
            i++;
        else if(j<s.length() && s[j]==res[k])
            j++;
        else
            return false;
        k++;
    }
    if(i<f.length()|| j<s.length())
        return false;
    return true;
}
int main()
{
    string first,second,result;
    cin>>first>>second>>result;
    bool res=CheckSuffle(first,second,result);
    if(res)
        cout<<"valid suffle";
    else
        cout<<"Not a Valid suffle";
}
