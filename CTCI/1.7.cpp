/*
 * =====================================================================================
 *       Filename:  1.7.cpp
 *    Description:  problem 1.7
 *        Version:  1.0
 *        Created:  12/27/2011 01:31:24 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
#define M 3
#define N 3
void changeToZero(int matrix[M][N])
{
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			if(matrix[i][j] == 0)
				matrix[i][0] = 0, matrix[0][j] = 0;
	for(int i=0;i<M;i++)
		if(matrix[i][0] == 0)
			for(int j=0;j<N;j++)
				matrix[i][j] = 0;
	for(int j=0;j<N;j++)
		if(matrix[0][j] == 0)
			for(int i=0;i<M;i++)
				matrix[i][j] = 0;
}

void printMatrix(int matrix[M][N])
{
	for(int i=0;i<M;i++)
	{	
		for(int j=0;j<N;j++)
			cout<<matrix[i][j]<<" " ;
		cout<<endl;
	}
	cout<<endl;
}


int main()
{
	int matrix[M][N] = {1,2,3,4,0,6,7,8,0 };
	printMatrix(matrix);
	changeToZero(matrix);
	printMatrix(matrix);
	return 0;
}
