#include<iostream>
#include<string>
using namespace std;
void RecPermutation(string soFar, string rest)
{
	if(rest=="") cout<<soFar<<endl;
	else
	{
		for(int i =0;i<rest.size();i++)
		{
			string next = soFar + rest[i];
			string remaining = rest.substr(0,i)+ rest.substr(i+1);
			RecPermutation(next,remaining);  
		}
	}
}

void ListPermutation(string s)
{
	RecPermutation("",s);
}
int main()
{
	ListPermutation("abcd");
	return 0;

}
