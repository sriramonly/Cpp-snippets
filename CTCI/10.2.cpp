/*
 * =====================================================================================
 *       Filename:  10.2.cpp
 *    Description:  sort an array of strings such that all anagrams in array are next to each other
 *        Version:  1.0
 *        Created:  12/31/2011 05:16:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

class compClass
{
	public:
	bool operator() (string s1,string s2)
	{
		sort(s1.begin(),s1.end());
		sort(s2.begin(),s2.end());
		return s1 <= s2;
	}

};

void sortStrings(string s[], int size)
{
	sort(s,s + size, compClass());
	for(int i =0;i<size;i++)
		cout<<s[i]<<" " ;
	cout<<endl;
}

void sortStringsUsingMap(string s[], int size)
{
	unordered_multimap<string,string> mp;
	for(int i=0;i<size;i++)
	{
		string temp = s[i];
		sort(s[i].begin(),s[i].end());
		mp.insert(make_pair(s[i],temp));
	}
	cout<<endl;

	//since key is the same(ie the sorted strings) for a long of strings, this loop prints all strings with same key together
	for(unordered_multimap<string,string>::iterator it = mp.begin();it != mp.end(); it++)
		cout<< (*it).second<<" ";
	cout<<endl;
}

int main()
{
	string s[] = {"abd","dab","tabhishek","abdx","bad","yry","xabd","try","daxb"};
	sortStrings(s,9);
	sortStringsUsingMap(s,9);

	return 0;
}

