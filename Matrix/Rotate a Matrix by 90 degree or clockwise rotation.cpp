#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
void reverse(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0,k=R-1;j<k;j++,k--)
        {
            swap(arr[i][j],arr[i][k]);
        }
    }
}
void transpose(int arr[R][C])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
    int arr[R][C];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>arr[i][j];
        }
    }
    transpose(arr);
    reverse(arr);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
