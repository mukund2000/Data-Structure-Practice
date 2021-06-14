#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(int nums[]) {
        int tor=nums[0];
        int hare=nums[0];
        do{
            tor=nums[tor];
            hare=nums[nums[hare]];
        }while(tor!=hare);
        tor=nums[0];
        while(tor!=hare)
        {
            tor=nums[tor];
            hare=nums[hare];
        }
        return hare;
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
    int res=findDuplicate(a);
    cout<<res<<"\n";
}