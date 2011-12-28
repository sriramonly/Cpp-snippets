/*
 * =====================================================================================
 *       Filename:  1.4.cpp
 *    Description:  problem 1.4
 *        Version:  1.0
 *        Created:  12/27/2011 02:07:48 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<string>
using namespace std;
void replaceSpaces(string & s)
{
	int i=s.size() - 1;
	while(s[i] == ' ')
		--i;
	for(int j = s.size() -1; i >= 0, j>=2; i--)
	{
		if(s[i] != ' ')
			s[j--] = s[i];
		else
			s[j] = '0', s[j-1] = '2', s[j-2] = '%', j -= 3;
	}
}

int main()
{
	string s= "Mr i am loving John Smith          ";
	replaceSpaces(s);
	cout<<s<<endl;
}

