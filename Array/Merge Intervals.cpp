#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct interval
{
    int s,e;
};
bool comp(interval a,interval b)
{
    return a.s<b.s;
}
void mergeinterval(interval a[],int n)
{
    sort(a,a+n,comp);
    int index=0;
    for(int i=1;i<n;i++)
    {
        if(a[index].e>=a[i].s)
        {
            a[index].e=max(a[index].e,a[i].e);
            a[index].s=min(a[index].s,a[i].s);
        }
        else
        {
            index++;
            a[index]=a[i];
            
        }
    }
    for(int i=0;i<=index;i++)
        {
            cout<<a[i].s<<" "<<a[i].e<<"\n";
        }
}
int main()
{
    int n;
    cin>>n;
    interval arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr->s>>arr->e;
    }
    mergeinterval(arr,n);
}