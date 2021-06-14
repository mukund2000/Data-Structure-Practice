#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        int strt=0,end=s.length()-1;
        while(strt<=end)
        {
            swap(s[strt],s[end]);
            strt++;
            end--;
        }
        cout<<s<<"\n";
    }
	//code
	return 0;
}
