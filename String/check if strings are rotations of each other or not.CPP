#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool CheckRotation(string f,string s)
{
    if(f.length()!=s.length())
        return false;
        string temp=f+f;
    return (temp.find(s)!=string::npos);
}
int main()
{
    string first,second;
    cin>>first>>second;
    bool res=CheckRotation(first,second);
    if(res)
        cout<<"valid rotation";
    else
        cout<<"Not a Valid rotation";
}
