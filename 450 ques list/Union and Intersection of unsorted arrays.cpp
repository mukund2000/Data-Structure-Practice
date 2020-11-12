#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void PrintUnion(int a[],int b[],int n,int m)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            cout<<a[i++]<<" ";
        }
        else if(a[i]>b[j])
        {
            cout<<b[j++]<<" ";
        }
        else
        {
            cout<<a[i++]<<" ";
            j++;
        }
    }
    while(i<n)
        cout<<a[i++]<<" ";
    while(j<m)
        cout<<b[j++]<<" ";
}
void PrintIntersection(int a[],int b[],int n,int m)
{
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(a[i]<b[j])
        {
            //cout<<a[i]<<" ";
            i++;
        }
        else if(a[i]>b[j])
        {
            //cout<<b[j++]<<" ";
            j++;
        }
        else
        {
            cout<<a[i++]<<" ";
            j++;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int j=0;j<m;j++)
        cin>>b[j];
    PrintUnion(a,b,n,m);
    cout<<"\n";
    PrintIntersection(a,b,n,m);
    return 0;
}
