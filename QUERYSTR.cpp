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
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void computeZArray(int z[],int n, char s[]){
    z[0] = 0;//1st element is always zero
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = (R-L); R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
                L = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            }
        }
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        char text[1000000];
        scanf("%s",text);
        int sz = strlen(text);
        reverse(text,text + sz);
        int Z[sz];
        for(int i =0;i<sz;i++)
            Z[i] = 0;
        computeZArray(Z,sz,text);
        Z[0] = sz;
        int n ;
        cin>>n;
        while(n--){
            int x;
            scanf("%d",&x);
            printf("%d\n", Z[sz-x]);
        }
    }

    return 0;
}
