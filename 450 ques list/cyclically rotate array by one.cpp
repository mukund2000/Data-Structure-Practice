#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin>>k;
    while(k--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int x=a[n-1];
        for(int i=n-1;i>0;i--)
        a[i]=a[i-1];
        a[0]=x;
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n";
    }
	//code
	return 0;
}
