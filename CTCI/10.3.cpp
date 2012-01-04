/*
 * =====================================================================================
 *
 *       Filename:  10.3.cpp
 *
 *    Description:  rotated binary search
 *
 *        Version:  1.0
 *        Created:  01/02/2012 03:27:23 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<iostream>
using namespace std;

int rotatedBinarySearch(int A[], int lo, int hi, int x)
{
	if(lo > hi)
		return -1; // failure
	int mid = lo + (hi-lo)/2;
	if(A[mid] == x)
		return mid;

	if(A[mid] < A[hi]) //if right half is normally ordered
	{
		if(A[mid] < x && x <= A[hi])
			return rotatedBinarySearch(A,mid+1,hi,x);
		else
			return rotatedBinarySearch(A,lo,mid-1,x);
	}

	else if(A[lo] <= A[mid]) //if left half is normally ordered
	{
		if(x >= A[lo] && x < A[mid])
			return rotatedBinarySearch(A,lo,mid-1,x);
		else
			return rotatedBinarySearch(A,mid+1,hi,x);
	}
 
	else if (A[mid] == A[hi]) 
	{
		//exceptional case: like: {2,2,2,3,4,2}     or {5,6,4,4,4} : remember this case
		//need to search both halves
		int result = rotatedBinarySearch(A,lo,mid-1,x);
		if(result == -1)
			return rotatedBinarySearch(A,mid+1,hi,x);
		else
			return result;
	}

	return -1; //not found in the array

}

int main()
{
//	int A[] = {5,1,2,3,4};
	int A[] = {5,6,4,4,4};
	cout<<rotatedBinarySearch(A,0,4,5)<<endl;
	cout<<rotatedBinarySearch(A,0,4,6)<<endl;
	cout<<rotatedBinarySearch(A,0,4,4)<<endl;
	return 0;
}
