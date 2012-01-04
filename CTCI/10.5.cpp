/*
 * =====================================================================================
 *       Filename:  10.5.cpp
 *    Description:  given a sorted array of strings interspersed with empty strings, write a method to find the location of a given string.
 *        Version:  1.0
 *        Created:  01/03/2012 08:59:53 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<string>
using namespace std;

//returns -1 ie failure for "": empty string :convention 
int findString(string input[],int lo,int hi,string toFind)
{
	if(lo > hi)
		return -1; //failure
	int mid = lo + (hi-lo)/2;
	int left = mid - 1, right = mid + 1;
	if(input[mid].compare("") == 0)
	{
		while(left >= lo && right <= hi)
		{
			--left, ++right;
			if(input[left].compare("") != 0 || input[right].compare("") != 0)
				break;
		}
		if(left >= lo && input[left].compare("") != 0)
			mid = left;
		else if(right <= hi && input[right].compare("") != 0)
			mid = right;
	}
//	cout<<mid<<endl;
	if(input[mid].compare(toFind) == 0)
		return mid;
	if(input[mid] < toFind)
		return findString(input,mid+1,hi,toFind);
	else
		return findString(input,lo,mid-1,toFind);
}

int main()
{
	string input[] = {"at","","","","","","","car","","","dad","",""};
	cout<<findString(input,0,12,"")<<endl;
	return 0;
}

