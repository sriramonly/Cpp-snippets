/*
 * =====================================================================================
 *       Filename:  ZAlgorithm.cpp
 *    Description:  Z Algorithm
 *        Version:  1.0
 *        Created:  03/07/2012 02:27:43 PM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<climits>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string text;
        scanf("\n");
        getline(cin,text);
        int sz = text.size();
        int ans = 0 ;
        for(int L = 1 ;L < sz ; L++){
            bool exists = true;
            int i = 0, j = 0;
            for(;i<sz && j<L;i++){
                if(text[i] == text[j++]){
                    if(j == L)
                        j = 0;
                    continue;
                }
                else{
                    exists = false;
                    break;
                }
            }
            if(exists == true && j == 0){
                ans = L;
                break;
            }
        }

        if(ans == 0)
            ans = sz;
        printf("%d\n",ans);
        if(T>0)
            printf("\n");
    }

    return 0;
}
