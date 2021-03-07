#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int aux[],int low,int mid,int high)
{
    int i,j,k;
    int inv_count=0;
    i=low;
    j=mid+1;
    k=low;
    while((i<=mid)&&(j<=high))
    {
        if(arr[i]<=arr[j])
        {
            aux[k++]=arr[i++];
        }
        else
        aux[k++]=arr[j++];
        inv_count+=(mid-i+1);
    }
    while(i<=mid)
    aux[k++]=arr[i++];

    while(j<=high)
    aux[k++]=arr[j++];

    for(i=low;i<=high;i++)
    {
        arr[i]=aux[i];
    }
    return inv_count;
}

int mergeSort(int arr[],int aux[],int low,int high)
{
    if(high==low)
    return 0;
    int mid,inv_count=0;
    if(high>=low)
    {
        mid=(low+high)/2;
        inv_count+=mergeSort(arr,aux,low,mid);
        inv_count+=mergeSort(arr,aux,mid+1,high);
        inv_count+=merge(arr,aux,low,mid,high);
    }
    return inv_count;

}

int inversionCount(int arr[], int N)
{
    int aux[N];
    return mergeSort(arr,aux,0,N);
    // Your Code Here
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
    cout<<inversionCount(a,n);
 }
