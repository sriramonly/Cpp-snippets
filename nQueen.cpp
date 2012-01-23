/*
 * =====================================================================================
 *       Filename:  nQueen.cpp
 *    Description: What is the maximum number of queens that can be placed on an  chessboard such that no two attack one another? The answer is queens, which gives 
 *    		   eight queens for the usual   board (Madachy 1979; Steinhaus 1999, p. 29). The number of different ways the  queens can be placed on an  chessboard so
 *    		   that no two queens may attack each other for the first few  are 1, 0, 0, 2, 10, 4, 40, 92, ...  
 *        Version:  1.0
 *        Created:  01/23/2012 12:18:36 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int A[N];
	for(int i =0 ;i<N;i++)
		A[i] = i;
	int ans = 0;
	do
	{
		bool status = true;
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
				if(abs(A[i]-A[j]) == abs(i-j))
					status = false;
		}
		if(status == true)
			++ans;
	}while(next_permutation(A,A+N));
	cout<<endl<<ans<<endl;
	return 0;
}
