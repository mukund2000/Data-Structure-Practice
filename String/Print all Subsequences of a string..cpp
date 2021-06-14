#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void Subsequence(string ip,string op)
{
    if(ip.length()==0)
    {
        cout<<op<<" ";
        return;
    }
    string op1=op;
    string op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    Subsequence(ip,op1);
    Subsequence(ip,op2);
}
int main()
{
    string ip;
    cin>>ip;
    Subsequence(ip,"");
}
