#include <iostream>
using namespace std;
#define MAX 1000
int Multiply(int x,int res[],int size);
void factorial(int n)
{
    int res[MAX];
    res[0]=1;
    int res_size=1;
    for(int i=2;i<=n;i++)
    {
        res_size=Multiply(i,res,res_size);
    }
    for(int i=res_size-1;i>=0;i--)
    {
        cout<<res[i];
    }
}
int Multiply(int x,int res[],int size)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int prod=res[i]*x+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        res[size]=carry%10;
        carry/=10;
        size++;
    }
    return size;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        factorial(n);
        cout<<endl;
    }
	//code
	return 0;
}
