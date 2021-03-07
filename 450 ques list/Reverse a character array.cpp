#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0,j=n-1;
        while(i<j)
        {
            char temp=s[i];
            s[i++]=s[j];
            s[j--]=temp;
        }

    }
int main()
{
    vector<char> s;
    int n;
    cin>>n;
    char x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s.push_back(x);
    }
    reverseString(s);
    for(auto i:s)
        cout<<i<<" ";
}
