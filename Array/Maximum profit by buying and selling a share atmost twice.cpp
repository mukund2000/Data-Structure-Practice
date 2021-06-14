#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maxProfitDP(int price[],int n)
{
    int *profit=new int[n];
    for(int i=0;i<n;i++)
    {
        profit[i]=0;
    }
    int max_price = price[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(price[i]>max_price)
            max_price=price[i];
        profit[i]=max(profit[i+1],max_price-price[i]);
    }
    int min_price=price[0];
    for(int i=1;i<n;i++)
    {
        if(price[i]<min_price)
            min_price=price[i];
        profit[i]=max(profit[i-1],profit[i]+(price[i]-min_price));
    }
    int res=profit[n-1];
    delete[] profit;
    return res;
}
/*
void maxProfit(int price[],int n)
{
    int profit=0;
    for(int i=1;i<n;i++)
    {
        int sub=price[i]-price[i-1];
        if(sub>0)
            profit+=sub;
    }
    cout<<"Maximum Profit: "<<profit<<endl;
}
*/
int main()
{

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<maxProfitDP(a,n);
}
