/*
 * =====================================================================================
 *       Filename:  prevPermutation.cpp
 *    Description:  Finding Previous permuation of a string. Same algorithm as nextPermutation
 *        Version:  1.0
 *        Created:  11/22/2011 02:58:42 AM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void prevPermutation(string s)
{
	int l = s.size();
	//string of size 0 or 1 :exit
	if(l==0 || l==1) 
		return;
	int i = l-1;
	while(i >=1 && s[i]>=s[i-1])
		--i;
	--i;
	if(i==-1)
	{
		cout<<"already in the first permutation";
		return;
	}
	int ii = l-1;
	while(ii>=i && s[ii] >= s[i])
		--ii;
	swap(s[i],s[ii]);
	reverse(s.begin()+i+1,s.end());	
	cout<<s<<endl;
}
int main()
{
	prevPermutation("56768");
	return 0;
}
