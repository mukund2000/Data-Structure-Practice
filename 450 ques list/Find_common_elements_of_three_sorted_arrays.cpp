#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> d;
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k])
                {
                    if(find(d.begin(),d.end(),A[i])==d.end())
                    {
                        d.push_back(A[i]);
                    }
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j])
                i++;
                else if(B[j]<C[k])
                j++;
                else
                k++;
            }
            return d;
            //code here.
        }
int main()
 {
     int n1,n2,n3;
     cin>>n1>>n2>>n3;
     vector<int> D;
     int A[n1],B[n2],C[n3];
     for(int i=0;i<n1;i++)
        cin>>A[i];
     for(int i=0;i<n2;i++)
        cin>>B[i];
     for(int i=0;i<n3;i++)
        cin>>C[i];
    D=commonElements(A,B,C,n1,n2,n3);
    for(int i=0;i<D.size();i++)
        cout<<D[i]<<" ";
 }
