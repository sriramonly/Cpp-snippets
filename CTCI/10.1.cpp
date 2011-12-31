/*
 * =====================================================================================
 *       Filename:  10.1.cpp
 *    Description:  given 2 sorted arrays with 1st array having sufficient extra space to accomodate 2nd array. Merge them without using any other extra space.
 *        Version:  1.0
 *        Created:  12/31/2011 04:45:26 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
void merge(int A[], int B[], int lastA, int lastB)
{
	int sizeA = lastA + lastB + 2;
	int k = sizeA - 1, i , j;
	for(i=lastA, j = lastB ; i>=0 && j>=0;)
	{
		cout<<"i: "<<i<<"|j: "<<j<<"| A[i]: "<<A[i]<<" | B[J]: " <<B[j]<<endl;
		int m = max(A[i],B[j]);
		if(m == A[i])
			--i;
		else
			--j;
		A[k--] = m;
	}
	//dont forget this case when A's index <0 and B's index is still >0)
	if(i<0 && j>=0)
		for(int k=j;k>=0;k--)
			A[k] = B[j--];
		
	cout<<"Merged array is : ";
	for(int i=0;i<sizeA;i++)
		cout<<A[i]<<" ";
	cout<<endl;
}

int main()
{
	int A[15] = {3,6,7,9,14,19};
	int B[] = {1,2,5,8,10,11,12,13,18};
	merge(A,B,5,8);
	return 0;
}


