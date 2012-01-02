/*
 * =====================================================================================
 *       Filename:  10.7.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  12/31/2011 06:21:06 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
class comparatorClass
{
	public:
	bool operator()(pair<int,int> p1, pair<int,int> p2 )
	{
		return p1.first < p2.first;
	}

};

void printPath(vector<pair<int,int> > v, int predecessor[],  int idx)
{
	if(idx == -1)
		return ;
	printPath(v, predecessor, predecessor[idx]);
	cout<<v[idx].first<<" "<<v[idx].second<<endl;
}

void LIS(vector<pair<int,int> > v)
{
	int n = v.size();
	int LIS[n], maxLISIndex = -1, maxlen = 0;
	int predecessor[n];
	for(int i=0;i<n;i++)
		LIS[i] = 1, predecessor[i] = -1; //-1 denotes no predecessor yet
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i].second < v[j].second)
			{
				int m = max(LIS[j],LIS[i] + 1);
				if(m != LIS[j])
					predecessor[j] = i;				
				LIS[j] = m;
			}
		}
		if(maxlen < LIS[i])
			maxlen = LIS[i], maxLISIndex = i;
	}
	cout<<maxlen<<" "<<maxLISIndex<<endl;
	cout<<"predecessor array: "; 
	for(int i=0;i<n;i++)
		cout<<predecessor[i]<<" ";				
	cout<<endl;
	printPath(v,predecessor,maxLISIndex);
}

void PrintLongestTower(vector<pair<int,int> > v)
{
	sort(v.begin(),v.end(),comparatorClass());
	LIS(v);
}

int main(){
	vector<pair<int,int> > v;
	v.push_back(make_pair(65,100));
	v.push_back(make_pair(70,150));
	v.push_back(make_pair(56,90));
	v.push_back(make_pair(75,190));
	v.push_back(make_pair(60,95));
	v.push_back(make_pair(68,110));
/* 
	for(int i=0 ;i<sizeof(A)/sizeof(int);i++)
		cout<<A[i]<<" " ;
*/
	cout<<endl;
	PrintLongestTower(v);
	return 0;
}
