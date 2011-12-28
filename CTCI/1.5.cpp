/*
 * =====================================================================================
 *
 *       Filename:  1.5.cpp
 *
 *    Description:  prblm 1.5
 *
 *        Version:  1.0
 *        Created:  12/27/2011 01:53:20 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
using namespace std;

string compress(string original)
{
	string ans = "";
	for(int i=0;i < original.size();i++)
	{
		ans += original[i];
		int len = 1, j;
		for(j=i+1;j<original.size();j++)
		{
			if(original[i] == original[j])
				++len; 
			else 
				break;
		}
		if(len > 0)
			ans += len+'0', i = j-1;	

	}
	if(ans.size() > original.size())
		return original;
	else 
		return ans;
}

int main()
{
	cout<<compress("aabcccccaaa")<<endl;
	cout<<compress("abbc")<<endl;
	return 0;
}
