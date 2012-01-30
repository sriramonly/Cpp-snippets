/*
 * =====================================================================================
 *       Filename:  stringTokenizer.cpp
 *    Description:  C++ implementation of C function strtok()
 *        Version:  1.0
 *        Created:  01/30/2012 01:26:06 AM
 *       Compiler:  gcc
 *         Author:  Kumar Abhishek (), kr.abhish@gmail.com
 * =====================================================================================
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void stringTokenizer(string &text, vector<string> &tokens,string delimiters=" ")
{
    size_t lastPos = text.find_first_not_of(delimiters,0);
    size_t pos = text.find_first_of(delimiters,lastPos);
    while((pos != string::npos) || (lastPos != string::npos))
    {
        tokens.push_back(text.substr(lastPos,pos-lastPos));
        lastPos = text.find_first_not_of(delimiters,pos);
        pos = text.find_first_of(delimiters,lastPos);
    }
}

int main()
{
    string delimiters = ";- ";
    vector<string> tokens;
    string text = "kf;kmfasf asfsf afasf4eeefdf- adfs";
    stringTokenizer(text, tokens, delimiters);
    for(int i = 0; i< tokens.size();i++)
        cout<<tokens[i]<<endl;
    return 0;
}
