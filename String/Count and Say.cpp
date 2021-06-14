#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";

        string res="11";
        for(int i=3;i<=n;i++)
        {
            string t="";
            res+="&";
            int c=1;
            for(int j=1;j<res.size();j++)
            {
               if(res[j]!=res[j-1])
               {
                   t+=to_string(c);
                   t+=res[j-1];
                   c=1;
               }
                else
                    c++;
            }
            res=t;
        }
        return res;
    }
int main()
{
    int n;
    cin>>n;
    cout<<countAndSay(n)<<"\n";
}
