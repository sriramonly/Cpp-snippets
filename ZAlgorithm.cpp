/*
 * =====================================================================================
 *
 *       Filename:  ZAlgorithm.cpp
 *
 *    Description:  Z Algorithm
 *
 *        Version:  1.0
 *        Created:  03/07/2012 02:27:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 *        Company:  
 *
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
    cin>>text>>pattern;
    string concat = pattern + '$' + text;
    computeZArray(Z,concat.size(),concat);

    /* 
       cout<<"Z array" << endl;
       for(int i =0;i<Z.size();i++)
       cout<<Z[i]<<" " ;
       cout<<endl;
   */

    bool found = false;
    for(int i = pattern.size()+1;i<concat.size();i++)
        if(Z[i] >= pattern.size()){
            found = true;
            cout<<"found: "<<i-pattern.size()-1<<endl;
        }
    if(found == false)
        cout<<"Not found"<<endl;
    return 0;
}
