//print all valid combinations of n pair of parentheses
#include<iostream>
using namespace std;

void printParentheses(string s,int k)
{
	if(k==0) 
	{
		cout<<s<<endl;
		return;
	}
	s += "(";
	printParentheses(s,k-1);
	s += ")";
	printParentheses(s,k-1);
}

int main()
{
	printParentheses("",4);
	return 0 ;
}
