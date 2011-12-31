/*
 * =====================================================================================
 *       Filename:  10.6.cpp
 *    Description:  find a number in a Young's tableau
 *        Version:  1.0
 *        Created:  12/31/2011 05:56:42 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
#define M 4
#define N 4

void searchMatrix(int A[M][N], int x)
{
	for(int i = M-1, j = 0; i>=0 && j <= N-1;)
	{
		if(x < A[i][j])
			--i;
		else if(x > A[i][j])
			++j;
		else
		{
			cout<<"Found x at: "<<i<<","<<j<<endl;
			return;
		}
	}
	cout<<"Not found"<<endl;
}

int main()
{
	int A[M][N] = {1,3,7,9,2,4,5,10,3,6,10,12,13,17,18,21};
	searchMatrix(A, 9);
	return 0;
}

