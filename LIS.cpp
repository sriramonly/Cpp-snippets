/*
 * =====================================================================================
 *       Filename:  LIS.cpp
 *    Description:  printing the Longest Increasing Subsequence in an array of n integers
 *        Version:  1.0
 *        Created:  12/31/2011 01:23:09 AM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
void printPath(int A[], int predecessor[],  int idx)
{
	if(idx == -1)
		return ;
	printPath(A, predecessor, predecessor[idx]);
	cout<<A[idx]<<" ";
}

void LIS(int A[],int n)
{
	int LIS[n], maxLISIndex = -1, maxlen = 0;
	int predecessor[n];
	for(int i=0;i<n;i++)
		LIS[i] = 1, predecessor[i] = -1; //-1 denotes no predecessor yet
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i] < A[j])
			{
				int m = max(LIS[j],LIS[i] + 1);
				if(m != LIS[j])
					predecessor[j] = i;				
				LIS[j] = m;
			}
		}
		if(maxlen < LIS[i])
			maxlen = LIS[i], maxLISIndex = i;
	}
	cout<<maxlen<<" "<<maxLISIndex<<endl;
	cout<<"predecessor array: "; 
	for(int i=0;i<n;i++)
		cout<<predecessor[i]<<" ";				
	cout<<endl;
	printPath(A,predecessor,maxLISIndex);
}

int main(){
	int A[] = {-3,1,5,-2,0,6,7,8,3,13,9,11};
	for(int i=0 ;i<sizeof(A)/sizeof(int);i++)
		cout<<A[i]<<" " ;
	cout<<endl;
	LIS(A,sizeof(A)/sizeof(int));
	return 0;
}
