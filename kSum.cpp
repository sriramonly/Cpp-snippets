/*
 * =====================================================================================
 *
 *       Filename:  kSum.cpp
 *
 *    Description:  Consider two sorted arrays of arbitary size, The aim is to find k minimum sums with the condition that there must be elements from both arrays
 *    		    in each sum. What is the best possible way to do this o(klogk) ?    example input
 *		    array1 =  [1,2,3,4,5,6,7]
 *    		    array2=   [3,4,7,9,15,17,25]
 *   		    find 3 smallest sums
 *  		    output : [4] =[3+1]  *                  [5]= [3+2]   *                  [5]=[4+1] 
 *        Version:  1.0
 *        Created:  11/19/2011 04:38:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int A[] = { 1,2,3,4,5,6,7};
int B[] = {3,4,7,9,15,17,25};

class comparator{
public:
	bool operator()(pair<int,int> &p, pair<int,int> & q) const 
	{
		return (A[p.first]+ B[p.second]  >  A[q.first] + B[q.second]);
	}

};
int main()
{
	priority_queue< std::pair<int,int >,vector<pair<int,int> >, comparator > q;//Note: vector<> here denotes what container will be used to store the priority queue, so must mention vector here in declaration of queue. 

	bool visited[sizeof(A)/sizeof(int)][sizeof(B)/sizeof(int)] = {false} ;//needed because indices pair get repeated when we insert (i+1,j) and (i,j+1)
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int i = q.top().first;
		int j = q.top().second;
		q.pop();
		cout<<A[i] + B[j] <<"|i: "<<i<<"|j:"<<j <<endl;
		if(i<6 && !visited[i+1][j] ) 
		{
			q.push(make_pair(i+1,j));
			visited[i+1][j] = true;
		}
		if(j<6 && !visited[i][j+1])
		{		
			q.push(make_pair(i,j+1));
			visited[i][j+1] = true;
		}
	}
	return 0;
}
