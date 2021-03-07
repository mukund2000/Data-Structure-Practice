/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.
Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13

Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76

Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18
*/
#include <bits/stdc++.h>
using namespace std;
int minCostPathHelper(int **input,int m,int n,int i,int j)
{
    // base class
    if(i==m-1 && j==n-1)
    {
        return input[i][j];
    }
    // when we are accessing element out of the bound then return infinite
    if(i>m-1 || j>n-1)
    {
        return INT_MAX;
    }
    // Recursive calls
    int leftcost=minCostPathHelper(input,m,n,i,j+1);
    int diagonalcost=minCostPathHelper(input,m,n,i+1,j+1);
    int downcost=minCostPathHelper(input,m,n,i+1,j);

    int ans=min(leftcost,min(diagonalcost,downcost))+input[i][j];
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    return minCostPathHelper(input,m,n,0,0);
	//Write your code here
}
int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}

/* Time Complexity: O(3^P) P=M*N
    Space Complexity: O(max(M,N)
*/
