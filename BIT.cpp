/*
 * =====================================================================================
 *       Filename:  BIT.cpp
 *    Description:  Implementation for Binary Indexed Trees  
 *        Version:  1.0
 *        Created:  12/26/2011 01:35:13 AM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;
//#define MAX 100007
#define MAX 5
int T[MAX+1]; //Define a space for BIT

//function to update: increment idxTH index in T[] by value val, we are not performing change in A[], we can do it , but we
//are directly updating the T[] array.
void update(int idx, int val)
{
	while(idx <= MAX)
	{
		T[idx] += val;
		idx += idx & -idx;
	}

}

//function to query
//find idxTH index in T[] array.
int query(int idx)
{
	int sum = 0;
	while(idx > 0 )
	{
		sum += T[idx];
		idx -= idx & -idx;
	}
	return sum;
}

void initializeBIT(int A[],int n)
{
	for(int i= 1; i<= n ;i++)
	{
		int idx = i;
		T[idx] += A[idx];
		while(idx <= MAX)
		{
			idx += idx & -idx;
			if(idx <= MAX)
			{
				T[idx] += A[i];
				cout<<"i : "<<i<<"| idx: "<<idx<<"| T[idx]: "<< T[idx]<<endl;
			}
		}
	}

}
 
int main()
{
	int A[] = {0,1,-1,2,4,3};
	for(int i= 1; i<= MAX ;i++)
		cout<<T[i]<<" ";
	
	cout<<endl;
	initializeBIT(A,5);
	for(int i= 1; i<= MAX ;i++)
		cout<<T[i]<<" ";
	
	cout<<endl<<query(5)- query(1)<<endl;
	update(4,7);//increment the 4th index in original A[] by 7.
	for(int i= 1; i<= MAX ;i++)
		cout<<T[i]<<" ";


	cout<<endl<<query(5)- query(1);
	
	return 0;
}
