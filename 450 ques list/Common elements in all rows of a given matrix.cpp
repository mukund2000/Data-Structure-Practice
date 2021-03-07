#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
void printCommon(int arr[R][C])
{
    unordered_map<int,int> mp;
    for(int j=0;j<C;j++)
       mp[arr[0][j]]=1;
    for(int i=1;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(mp[arr[i][j]]==i)
            {
                mp[arr[i][j]]=i+1;
                if(i==C-1)
                    cout<<arr[i][j]<<" ";
            }
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
    printCommon(arr);
}
