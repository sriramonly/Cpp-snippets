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

void permute(string s,int i)
{
	if(i == s.size() )
		cout<<s<<endl;
	for (int j=i ;j<s.size() ;j++ )
	{
		swap(s[i],s[j]);
		permute(s,i+1);
		swap(s[i],s[j]);
	}
}

int main()
{
	ListPermutation("mno");
	permute("abc",0);
	return 0;

}
