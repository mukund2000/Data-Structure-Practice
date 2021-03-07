#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int getMedians(int a[],int b[],int n)
{
    int i=0,j=0,k;
    int m1=-1,m2=-1;
    for(k=0;k<=n;k++)
    {
        if(i==n)
        {
            m1=m2;
            m2=b[0];
            break;
        }
        if(j==n)
        {
            m1=m2;
            m2=a[0];
            break;
        }
        if(a[i]<=b[j])
        {
            m1=m2;
            m2=a[i];
            i++;
        }
        else
        {
            m1=m2;
            m2=b[j];
            j++;
        }
    }
    return (m1+m2)/2;
}
int median(int arr[],int n)
{

    if(n%2==0)
    {
        return (arr[n/2]+arr[n/2-1])/2;
    }
    else
        return arr[n/2];
}

int GetMEdians(int a[],int b[],int n)
{
    if(n<=0)
        return -1;
    if(n==1)
        return (a[0]+b[0])/2;
    if(n==2)
        return (max(a[0],b[0])+min(a[1],b[1]))/2;
    int m1=median(a,n);
    int m2=median(b,n);
    if(m1==m2)
        return m1;
    if(m1<m2)
    {
        if(n%2==0)
            return GetMEdians(a+n/2-1,b,n-n/2+1);
        else
            return GetMEdians(a+n/2,b,n-n/2);
    }
    else
    {
        if(n%2==0)
        {
            return GetMEdians(a,b+n/2-1,n-n/2+1);
        }
        else
            return GetMEdians(a,b+n/2,n-n/2);
    }

}


int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    cout<<GetMEdians(a,b,n)<<"\n";
}
