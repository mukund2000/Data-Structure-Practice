#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int strt=0,end=n-1;
    while(strt<=end)
    {
        swap(a[strt],a[end]);
        strt++;
        end--;
    }
    for(int j=0;j<n;j++)
        cout<<a[j]<<" ";
	//code
	return 0;
}
