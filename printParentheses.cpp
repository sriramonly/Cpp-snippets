//print all valid combinations of n pair of parentheses
#include<iostream>
using namespace std;
bool isValidParenthesization(string s)
{
	int cnt = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(') ++cnt;
		else --cnt;
		if(cnt<0) return false;
	}
	if(cnt==0) return true;
	else return false;
}

void printParentheses(string s,int i)
{
	if(i== s.size()) 
	{
		if(isValidParenthesization(s)) 
			cout<<s<<endl;
		return;
	}
		s[i] = '(';
		printParentheses(s,i+1);
		s[i] = ')';
		printParentheses(s,i+1);
}

int main()
{
	string s="******";
	printParentheses(s,0);
	return 0 ;
}
