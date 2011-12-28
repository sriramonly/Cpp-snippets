/*
 * =====================================================================================
 *
 *       Filename:  nextPermutation.cpp
 *
 *    Description:  printing next permutation/algorithm : http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 *
 *        Version:  1.0
 *        Created:  11/19/2011 06:39:13 AM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

void nextPermutation(string s)
{
	int sz =s.size(), k ;
	if(sz == 0 || sz == 1) return; //skip if string of size 0 or 1.
	for(k = sz-2 ; k>=0 ; k--)
		if(s[k] < s[k+1])
			break;
	if(k==-1)
	{
		cout<<"Already the last permutation";
		return;
	}
	int l =sz;
	while(s[k] >= s[l])	
		--l;
	swap(s[k],s[l]);
	reverse(s.begin() + k+1,s.end());	
	cout<<endl<<s<<endl;
}
int main()
{
	nextPermutation("apqbxyz");
	return 0;
}

