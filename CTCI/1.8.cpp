/*
 * =====================================================================================
 *       Filename:  1.8.cpp
 *    Description:  problem 1.8
 *        Version:  1.0
 *        Created:  12/27/2011 01:23:18 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
using namespace std;

bool isSubstring(string substr,string originalString)
{
        if(originalString.find(substr) != string::npos)
                return true;
        else
                return false;
}

bool isRotation(string s2, string s1) //s2 a rotation of s1.
{
	if(s2.size() == s1.size() && s1.size() > 0)
		return isSubstring(s2,s1+s1);
}

int main()
{
        cout<<isRotation("waterbottle","erbottlewat");
        return 0;
}

