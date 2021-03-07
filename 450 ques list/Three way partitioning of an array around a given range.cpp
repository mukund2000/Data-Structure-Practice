#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void threeWayPartition(int arr[],int n,int a, int b)
    {

       int start=0,end=n-1;
       for(int i=0;i<=end;)
       {
           if(arr[i]<a)
           swap(arr[i++],arr[start++]);
           else if(arr[i]>b)
           swap(arr[i],arr[end--]);
           else
           i++;
       }// code here
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
    int LowVal,HighVal;
    cin>>LowVal>>HighVal;
    threeWayPartition(a,n,LowVal,HighVal);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}
