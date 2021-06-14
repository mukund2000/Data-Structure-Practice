#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void reArrange(int arr[],int n)
{
    int i=-1,j=n-1;
    while(i<j)
    {
        while(i<=n-1 && arr[i]>0)
            i++;
        while(j>=0 && arr[j]<0)
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    if(i==0|| i==n)
        return;
    int k=0;
    while(i<n && k<n)
    {
        swap(arr[i],arr[k]);
        i++;
        k+=2;
    }
}

int main()
 {
     int n;
     cin>>n;
     int a[n];
     for(int i=0;i<n;i++)
     {
         cin>>a[i];
     }
     reArrange(a,n);
     for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
 }
