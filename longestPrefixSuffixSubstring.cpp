/*
 * =====================================================================================
 *       Filename:  ZAlgorithm.cpp
 *    Description:  Find the longest substring(does not at beginning or end) which is a prefix as well as a suffix.
 *                  http://codeforces.com/contest/126/problem/B: using Z algorithm. Total time: O(n)
 *        Version:  1.0
 *        Created:  03/07/2012 02:27:43 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void computeZArray(vector<int> &z,int n, string s){
    z.push_back(0);//1st element is always zero
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z.push_back(R-L); R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z.push_back(z[k]);
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z.push_back(R-L); R--;
            }
        }
    }
}

int main(){
    vector<int> Z;
    string text, pattern;
    cin>>text;
    computeZArray(Z,text.size(),text);

    int maxi = 0, ans=0;
    int n = Z.size();
    for(int i =1;i<n;i++){
        if(Z[i] == n-i && maxi >= n-i){
            ans = i;
            break;
        }
        if(Z[i] > 0)
            maxi = max(maxi,Z[i]);
    }
    if(ans != 0 )
       cout<<text.substr(ans)<<endl;
    else
        cout<<"Just a legend"<<endl;

    return 0;
}
