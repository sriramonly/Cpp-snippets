#include<iostream>
#include<string>
using namespace std;
void nextPermutation(string soFar, string rest, string toFindNext,bool &isSet)
{
	if(rest=="")
	{
		if(isSet == true)
		{
			cout<<soFar<<endl;
			throw std::exception() ;
			return;

		}		
		if(soFar.compare(toFindNext) == 0)
			isSet = true;
	}
	else
	{
		for(int i =0;i<rest.size();i++)
		{
			string next = soFar + rest[i];
			string remaining = rest.substr(0,i)+ rest.substr(i+1);
			nextPermutation(next,remaining,toFindNext,isSet);  
		}
	}

}
  
void prevPermutation(string soFar, string rest, string toFindPrev,string &cache)
{
	if(rest=="")
	{
		if(soFar.compare(toFindPrev) == 0)
		{
			cout<<cache<<endl;
			throw std::exception();
		}
		cache = soFar;
	}
	else
	{
		for(int i =0;i<rest.size();i++)
		{
			string next = soFar + rest[i];
			string remaining = rest.substr(0,i)+ rest.substr(i+1);
			prevPermutation(next,remaining,toFindPrev,cache);  
		}
	}

}

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
//	ListPermutation("mno");
//	permute("abc",0);
	try
	{
		bool isSet = false;
		//nextPermutation("","abcd","abcd",isSet);
		string cache = "";
		prevPermutation("","abcd","dabc",cache);
	}
	catch(exception e)
	{

	}

	return 0;

}
