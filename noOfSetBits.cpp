/*
 * =====================================================================================
 *       Filename:  noOfSetBits.cpp
 *    Description:  Calculates the number of set bits in all the numbers from 1 to N
 *        Version:  1.0
 *        Created:  01/09/2012 10:56:33 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<cmath>
using namespace std;
//for given k, find greatest ans such that, (2^ans)-1 <= k
int lowestPower2LessOneThanK(int k)
{
	int ans = 1;
	while(ans<=k)
		ans *= 2;
	if(k == ans - 1)
		return k;
	ans /= 2;
	return ans - 1;
}
int noSetBits(int N)
{
	if(N <= 0)
		return 0;
	if(N == 1) 
		return 1;
	int ans = 0;
	int k = ceil(log2(N));
	int m = lowestPower2LessOneThanK(N);
	int  p = ceil(log2(m));
	int pp = p * (int)pow(2,p-1);

	//ans is 2^ans -1 + (no. of highest set bits in all numbers from ans+1 to N )+ number of set bits from (ans+1)>>1 to N>>1
	//ie. 000, 001, 010, 011, 1#00, 1#01, 1#10
	ans = pp + (N - m)+  noSetBits(N-m-1);
	return ans;
}

int main()
{
	cout<<noSetBits(53);
	return 0;
}
