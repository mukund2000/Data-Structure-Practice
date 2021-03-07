#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int isPlaindrome(string S)
	{
	    int n=S.length();
	    int i=0,j=n-1;
	    while(i<j)
	    {
	        if(S[i]==S[j])
	        {
	            i++;
	            j--;
	        }
	        else
	        return 0;
	    }
	    return 1;
	    // Your code goes here
	}
int main()
{
    string s;
    cin>>s;
    cout<<isPlaindrome(s);
}
