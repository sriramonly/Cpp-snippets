#include<iostream>
#include<string>
using namespace std;

void recSubset(string soFar, string rest)
{
	if(rest == "") cout<<soFar<<endl;
	else
	{
		string next = soFar + rest[0];
		string remaining = rest.substr(1);
		recSubset(next,remaining);
		recSubset(soFar,remaining);
	}
}


void ListSubset(string s)
{
	recSubset("",s);
}

int main()
{
ListSubset("abcd");
return 0;
}
